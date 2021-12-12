import sys

# "Define MACROs"
default_dictionary = "numbers.dict"

def main():
    argc = len(sys.argv)
    argv = sys.argv

    if (argc > 3 or argc < 2):
        print("Usage: python3 rush02.py [dict_name] number")
        return ()
        
    if (argc == 2):
        number_string = sys.argv[1]
        # ft_atoi equivalent
        number = int(number_string)
    
    if (argc == 3):
        number_string = sys.argv[2]
        # ft_atoi equivalent
        number = int(number_string)
        special_dictionary_string = sys.argv[1]
        special_dictionary = parse_file(special_dictionary_string)
        special_number_found = print_special_number(number, special_dictionary)
        if special_number_found:
            return ()
    
    # Question: Will the special dictionary have all the regular entries as well (and we only use the special dictionary) or will it have only the special values and we still use the regular dictionary if we have to fall back on regular parsing?

    dictionary = parse_file(default_dictionary)
    print_whole_number(number, dictionary)
    

def print_single_digit(number, is_first_elem, lut_dict):
    '''Prints a single digit number
    
    Given a single digit number (0-9). Prints the corresponding word for that number.
    
    Args:
        number (int): the number to be printed. In range 0-9.
    '''
    # Early returns if the number is zero and does nothing (you don't want it to print "zero" unless it is the case where the whole number is just zero which is already caught in the initial entry function. In the recursive calls (which this is primarily used for) you want to print /nothing/ if you come across a zero as it is likely from a 000 triplet or similar)
    if number == 0:
        return ()
    number_word = lut_dict[number]
    if (is_first_elem == 0):
        print_space()
    print(f"{number_word}", end = "")
    

def print_double_digit(number, is_first_elem, lut_dict):
    '''Prints a two digit number

    Given a two digit number (00-99). Prints the corresponding words for that number.

    Args:
        number (int): the number to be printed. In range 00-99.
    '''
    # First handle the digits alone and the special "teens cases"
    if (number > 0 and number < 20):
        combined_word = lut_dict[number]
        if (is_first_elem == 0):
            print_space()
        print(f"{combined_word}", end = "")
        
    # Handle double digits that can be split (not teens).
    if (number >= 20):
        # Pull out and print the tens value's digit (twenty, thirty, forty, etc).
        tens_value = number // 10 * 10
        tens_word = lut_dict[tens_value]
        if (is_first_elem == 0):
            print_space()
        print(f"{tens_word}", end = "")
        is_first_elem = 0

        # Then get single digit and print the single digit by calling single digit printer.
        ones_value = number % 10
        print_single_digit(ones_value, is_first_elem, lut_dict)

def print_triple_digit(number, is_first_elem, lut_dict):
    '''Prints a three digit number

    Given a three digit number (000-999) Prints the corresponding words for that number. 
    
    Does this by calling the print_double_digit and print_single_digit functions.

    Also passed in a flag to tell the function whether there is number value (and hence words) before this triplet. If there is, then it prepends the output with a the word "and" or a comma as appropriate.

    Eg if:
    prior data = 0: number = 123 will output: one hundred and twenty three
    prior data = 1: number = 123 will output: , one hundred and twenty three

    Args:
        number (int): The three digit number in range 000-999
        is_first_elem (int): Flag for whether this is the "highest" triplet or not.
            1: is the first element. This is the "highest" triplet
            0: isn't the first element. This is a in-the-middle triplet (and therefore prepend the joining words/commas)
    '''
    # If number >99 then print hundreds digit
    if (number >= 100):
        if (is_first_elem == 0):
            print_comma()    
        hundreds_value = number // 100 * 100
        print_single_digit(hundreds_value // 100, is_first_elem, lut_dict)
        
        # ... then the word "hundred"
        hundred = 100 # I chose not to hard code this look up so if they want us to replace the word "hundred" with something else, we can easily
        hundreds_word = lut_dict[hundred]
        print_space()
        print(f"{hundreds_word}", end = "")
        
        # Since we printed something, override the is_first_elem flag to 0
        is_first_elem = 0

    # Handling of the lesser two digits
    double_digit_num = number % 100
    if (double_digit_num):
        # If there was prior data, print preceeding word "and"
        if (is_first_elem == 0):
            print_space()
            print("and", end = "")
        # Then call print_double_digit
        print_double_digit(double_digit_num, is_first_elem, lut_dict)

def print_comma():
    '''Prints a comma'''
    # Prints a comma /without/ a space. The space will be added by the prefix add from the regular triplet handling
    print(f",", end = "")

def print_space():
    '''Prints a space'''
    print(f" ", end = "")

def print_multiplier(multiplier, lut_dict):
    '''Prints the multiplier word
    
    Given a multiplier, looks for it in the value: words dictionary and prints the multiplier word.

    Early returns if the multiplier is 1 and does not print a multiplier (Ie if multiplier = 1 then we are working with the smallest triplet, and therefore shouldn't have a trailing multiplier word. 23 is just "twenty three", not "twenty three ones")

    Args:
        multiplier (int): an integer containing how much you would multiply the number by to get the actual value. Eg if we are working on the "thousands" triplet then the multiplier passed in will be 1000.
    '''
    # Early return and don't print multiplier if multiplier is 1
    if multiplier == 1:
        return ()
    multiplier_word = lut_dict[multiplier]
    print_space() # This one always prints prefix space as the only way you end up here is if there was a word printed before.
    print(f"{multiplier_word}", end = "")
    
def process_triplet(number, multiplier, is_first_elem, lut_dict):
    ''' Recursively processes triplets

    Processes number with head recursion. If the number is higher than a triplet (>=1000) then it recursively calls itself with a multiplier 1000 higher. Then after the higher triplets are processed it handles the lowest triplet.

    It cleaves off the lowest triplet and passes it to a function that prints the lowest triplet (but only if the lowest triplet is not zero).

    Prior to this it checks and sets a flag to say whether there is higher data and passes this into the triple digit printing function. This is used to deterine whether to print a prepend "and" or "," (or space?).

    Finally calls a function that prints the multiplier word (thousand, million, billion, etc)

    Args:
        number (int): The number being parsed. when recursively called this has the lower digits chopped off. Ie if the original number was 123456, the recursive call will only receive 123.
        multiplier (int): The multiplier of this triplet (eg 1000, 1000000, 1000000000). This is used to keep track of which multiplier word to print when the time comes.
    '''
    # Head recursion to send off any amount higher than the lowest 999 to be handled by the next call
    # Also, sets updates is_first_elem flag to be passed into the print_triple_digit function
    if (number >= 1000):
        process_triplet(number // 1000, multiplier * 1000, is_first_elem, lut_dict)
        is_first_elem = 0
    
    # Gets the lowest three digits
    triple_digit_num = number % 1000
    
    # Calls the function to print the triple digits, /if/ there is anything to print (ie if this triplet is 000 then don't call/print anything).
    if (triple_digit_num > 0):
        print_triple_digit(triple_digit_num, is_first_elem, lut_dict)
        print_multiplier(multiplier, lut_dict)

def print_negative():
    '''Prints the word "negative"'''
    # Unlike the rest of the functions, this one intentionally has trailing space
    print(f"negative", end = "")
    print_space()

def print_whole_number(number, lut_dict):
    '''Prints a number's value in words

    Ie 123 outputs "one hundred and twenty three"

    Args:
        number (int): An integer to print

    Returns:
        nothing
    '''
    # Special handling for the value zero to print out the word "zero"
    if number == 0:
        zero_word = lut_dict[number]
        print(f"{zero_word}", end = "")
        return(0)

    # Handle negative values by printing "negative" and inverting value
    if number < 0:
        print_negative()
        number = number * -1

    # Start the recursive processing on the number. Seed the multiplier with 1. Seeds "is_first_elem with 1"
    process_triplet(number, 1, 1, lut_dict)
    print("") # Print a new line

def print_special_number(number, lut_dict):
    string_to_print = lut_dict.get(number, None)
    if string_to_print:
        print(string_to_print)
        return (1)
    return (0)

def parse_file(path):
    f = open(path, "r")
    file_contents = f.read()
    lines = file_contents.splitlines()

    lut_dictionary = {}
    
    for line in lines:
        if line[:2] != "//":
            [val, word] = line.split(":")
            val = int(val.strip())
            word = word.strip()
            lut_dictionary[val] = word

    return lut_dictionary

# Don't worry about this. This is a python boilerplate script invoking thing
if __name__ == "__main__":
    main()

# # Bin
# default_lookup = {
#     0: "zero",
#     1: "one",
#     2: "two",
#     3: "three",
#     4: "four",
#     5: "five",
#     6: "six",
#     7: "seven",
#     8: "eight",
#     9: "nine",
#     10: "ten",
#     11: "eleven",
#     12: "twelve",
#     13: "thirteen",
#     14: "fourteen",
#     15: "fifteen",
#     16: "sixteen",
#     17: "seventeen",
#     18: "eighteen",
#     19: "nineteen",
#     20: "twenty",
#     30: "thirty",
#     50: "fifty",
#     60: "sixty",
#     70: "seventy",
#     80: "eighty",
#     90: "ninety",
#     100: "hundred",
#     1000: "thousand",
#     1000000: "million",
#     1000000000: "billion",
#     1000000000000: "trillion",
#     1000000000000000: "quadrillion",
#     1000000000000000000: "quintillion",
#     1000000000000000000000: "sextillion",
#     1000000000000000000000000: "septillion",
#     1000000000000000000000000000: "octillion",
#     1000000000000000000000000000000: "nonillion",
#     1000000000000000000000000000000000: "decillion",
#     1000000000000000000000000000000000000: "undecillion",
# }

# special_lookup = {
#     70: "banana",
#     21: "blah",
#     42: "the meaning of life, the universe, and everthing",
# }
