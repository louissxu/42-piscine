import sys

# "Define MACROs"
default_dictionary = "numbers.dict"

def main():
    argc = len(sys.argv)
    argv = sys.argv

    if (argc > 3 or argc < 2):
        print("Usage: python3 rush02.py [dict_name] number")
        return ()
        
    # ft_atoi equivalent
    number = int(sys.argv[1])
    
    if (argc == 2):
        dictionary = parse_file(default_dictionary)
        print_whole_number(number)
    
    if (argc == 3):
        number = int(sys.argv[2])
        # Parse default dictionary, then
        # Parse special dictionary?
        special_number_found = print_special_number(number)
        if (not special_number_found):
            print_whole_number(number)

    


def print_single_digit(number, has_prior_data):
    '''Prints a single digit number
    
    Given a single digit number (0-9). Prints the corresponding word for that number.
    
    Args:
        number (int): the number to be printed. In range 0-9.
    '''
    # Early returns if the number is zero and does nothing (you don't want it to print "zero" unless it is the case where the whole number is just zero which is already caught in the initial entry function. In the recursive calls (which this is primarily used for) you want to print /nothing/ if you come across a zero as it is likely from a 000 triplet or similar)
    if number == 0:
        return ()
    number_word = default_lookup[number]
    if (has_prior_data):
        print("_")
    print(f"{number_word}")
    

def print_double_digit(number, has_prior_data):
    '''Prints a two digit number

    Given a two digit number (00-99). Prints the corresponding words for that number.

    Args:
        number (int): the number to be printed. In range 00-99.
    '''
    # First handle the digits alone and the special "teens cases"
    if (number > 0 and number < 20):
        combined_word = default_lookup[number]
        if (has_prior_data):
            print("_")
        print(f"{combined_word}")
        
    # Handle double digits that can be split (not teens).
    if (number >= 20):
        # Pull out and print the tens value's digit (twenty, thirty, forty, etc).
        tens_value = number // 10 * 10
        tens_word = default_lookup[tens_value]
        if (has_prior_data):
            print("_")
        print(f"{tens_word}")
        has_prior_data = 1

        # Then get single digit and print the single digit by calling single digit printer.
        ones_value = number % 10
        print_single_digit(ones_value, has_prior_data)

def print_triple_digit(number, has_prior_data):
    '''Prints a three digit number

    Given a three digit number (000-999) Prints the corresponding words for that number. 
    
    Does this by calling the print_double_digit and print_single_digit functions.

    Also passed in a flag to tell the function whether there is number value (and hence words) before this triplet. If there is, then it prepends the output with a the word "and" or a comma as appropriate.

    Eg if:
    prior data = 0: number = 123 will output: one hundred and twenty three
    prior data = 1: number = 123 will output: , one hundred and twenty three

    Args:
        number (int): The three digit number in range 000-999
        has_prior_data (int): Flag for whether this is the "highest" triplet or not.
            0: no higher data. This is the "highest" triplet
            1: has higher data. This is a in-the-middle triplet (and therefore prepend the joining words/commas)
    '''
    # If number >99 then print hundreds digit
    if (number >= 100):
        if (has_prior_data):
            print_comma()    
        hundreds_value = number // 100 * 100
        print_single_digit(hundreds_value // 100, has_prior_data)
        
        # ... then the word "hundred"
        hundred = 100 # I chose not to hard code this look up so if they want us to replace the word "hundred" with something else, we can easily
        hundreds_word = default_lookup[hundred]
        print("_")
        print(f"{hundreds_word}")
        
        # Since we printed something, override the has_prior_data flag to 1
        has_prior_data = 1

    # Handling of the lesser two digits
    double_digit_num = number % 100
    if (double_digit_num):
        # If there was prior data, print preceeding word "and"
        if (has_prior_data):
            print("_")
            print("and")
        # Then call print_double_digit
        print_double_digit(double_digit_num, has_prior_data)

def print_comma():
    '''Prints a comma'''
    # Prints a comma /without/ a space. The space will be added by the prefix add from the regular triplet handling
    print(f",")

def print_multiplier(multiplier):
    '''Prints the multiplier word
    
    Given a multiplier, looks for it in the value: words dictionary and prints the multiplier word.

    Early returns if the multiplier is 1 and does not print a multiplier (Ie if multiplier = 1 then we are working with the smallest triplet, and therefore shouldn't have a trailing multiplier word. 23 is just "twenty three", not "twenty three ones")

    Args:
        multiplier (int): an integer containing how much you would multiply the number by to get the actual value. Eg if we are working on the "thousands" triplet then the multiplier passed in will be 1000.
    '''
    # Early return and don't print multiplier if multiplier is 1
    if multiplier == 1:
        return ()
    multiplier_word = default_lookup[multiplier]
    print("_") # This one always prints prefix space as the only way you end up here is if there was a word printed before.
    print(f"{multiplier_word}")
    
def process_triplet(number, multiplier, has_prior_data):
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
    # Also, sets updates has_prior_data flag to be passed into the print_triple_digit function
    if (number >= 1000):
        process_triplet(number // 1000, multiplier * 1000, has_prior_data)
        has_prior_data = 1
    
    # Gets the lowest three digits
    triple_digit_num = number % 1000
    
    # Calls the function to print the triple digits, /if/ there is anything to print (ie if this triplet is 000 then don't call/print anything).
    if (triple_digit_num > 0):
        print_triple_digit(triple_digit_num, has_prior_data)
        print_multiplier(multiplier)

def print_negative():
    '''Prints the word "negative"'''
    # Unlike the rest of the functions, this one intentionally has trailing space
    print(f"negative")
    print("_")

def print_whole_number(number):
    '''Prints a number's value in words

    Ie 123 outputs "one hundred and twenty three"

    Args:
        number (int): An integer to print

    Returns:
        nothing
    '''
    # Special handling for the value zero to print out the word "zero"
    if number == 0:
        zero_word = default_lookup[number]
        print(f"{zero_word}")
        return(0)

    # Handle negative values by printing "negative" and inverting value
    if number < 0:
        print_negative()
        number = number * -1

    # Start the recursive processing on the number. Seed the multiplier with 1. Seeds "has_prior_data with 0"
    process_triplet(number, 1, 0)

def print_special_number(number):
    string_to_print = special_lookup.get(number, None)
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
