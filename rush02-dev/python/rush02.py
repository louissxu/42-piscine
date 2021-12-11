import sys

argc = len(sys.argv)
argv = (sys.argv)

input_string = argv[1]
input_number = int(input_string) # ft_atoi
print(f" input number is: {input_number}")

default_lookup = {
    0: "zero",
    1: "one",
    2: "two",
    3: "three",
    4: "four",
    5: "five",
    6: "six",
    7: "seven",
    8: "eight",
    9: "nine",
    10: "ten",
    11: "eleven",
    12: "twelve",
    13: "thirteen",
    14: "fourteen",
    15: "fifteen",
    16: "sixteen",
    17: "seventeen",
    18: "eighteen",
    19: "nineteen",
    20: "twenty",
    30: "thirty",
    50: "fifty",
    60: "sixty",
    70: "seventy",
    80: "eighty",
    90: "ninety",
    100: "hundred",
    1000: "thousand",
    1000000: "million",
    1000000000: "billion",
    1000000000000: "trillion",
    1000000000000000: "quadrillion",
    1000000000000000000: "quintillion",
    1000000000000000000000: "sextillion",
    1000000000000000000000000: "septillion",
    1000000000000000000000000000: "octillion",
    1000000000000000000000000000000: "nonillion",
    1000000000000000000000000000000000: "decillion",
    1000000000000000000000000000000000000: "undecillion",
}

def print_single_digit(number):
    if number == 0:
        return ()
    number_word = default_lookup[number]
    print(f"{number_word}")

def print_double_digit(number):
    if (number > 0 and number < 20):
        combined_word = default_lookup[number]
        print(f"{combined_word}")
    
    if (number >= 20):
        tens_value = number // 10 * 10
        tens_word = default_lookup[tens_value]
        print(f"{tens_word}")
        ones_value = number % 10
        print_single_digit(ones_value)

def print_triple_digit(number, has_prior_data):
    if (number >= 100):
        hundreds_value = number // 100 * 100
        print_single_digit(hundreds_value // 100)
        
        hundred = 100 # hard code this?
        hundreds_word = default_lookup[hundred]
        print(f"{hundreds_word}")

    if ((number // 100 and number % 100) or (has_prior_data and number % 100)):
        print(f"and")

    double_digit_num = number % 100
    print_double_digit(double_digit_num)

def print_multiplier(multiplier):
    if multiplier == 1:
        return ()
    multiplier_word = default_lookup[multiplier]
    print(f"{multiplier_word}")

def print_comma(multiplier, triple_digit_num, has_prior_data):
    if (multiplier != 1):
        print(f",")

def process_triplet(number, multiplier):
    if (number >= 1000):
        process_triplet(number // 1000, multiplier*1000)
    
    triple_digit_num = number % 1000
    
    has_prior_data = 0
    if (number // 1000):
        has_prior_data = 1
    
    if (triple_digit_num > 0):
        print_triple_digit(triple_digit_num, has_prior_data)
        print_multiplier(multiplier)
        print_comma(multiplier, triple_digit_num, has_prior_data)

def print_whole_number(number):
    if number == 0:
        zero_word = default_lookup[number]
        print(f"{zero_word}")
        return(0)
    process_triplet(input_number, 1)

print_whole_number(input_number)

# handle negatives
# handle commas
# handle spaces