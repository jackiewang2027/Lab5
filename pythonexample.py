"""
Joshua Brunk and Weien Xu

Sources: https://www.geeksforgeeks.org/python-program-for-binary-search/
"""
import time
from stringdata import get_data


# Searches linearly through the container
def linear_search(container, string):
    print("Linear search for: ", string)
    begin_time = time.time()  # Takes starting time
    print("Beginning time", begin_time)
    for index, stringy in enumerate(container):  # Loop through the entire tuple
        if stringy == string:  # If the string is the same as the string you found it!
            end_time = time.time()
            print("Found in Tuple")
            print("Time Delta", end_time - begin_time)
            return index
        elif index == len(container) - 1:  # If you reached the end without finding the string than it isn't here
            print("Not Found In Tuple")
            end_time = time.time()
            print("Time Delta", end_time - begin_time)
            return -1


# This is my original writing of binary search but it is slower than the linear on average case for some reason
# def binary_search(container, string):
#   og = container
#   print("Binary search for: ", string)
#   begin_time = time.time()
#   print("Beginning time", begin_time)
#   beforesort = time.time()
#   container = sorted(container)
#   aftersort = time.time()
#   print(aftersort-beforesort, "sort time")
# print("first sorted", len(container))
# print(len(container), "first len")
#   while True:
#       if container[len(container)//2] < string and len(container) > 1:
#           container = container[len(container)//2:]
# print("other slice", len(container))
#       elif container[len(container)//2] > string and len(container) > 1:
#           container = container[:len(container)//2]
#       elif container[len(container)//2] == string:
#           end_time = time.time()
#           print("Time Delta", end_time - begin_time)
#           return og.index(string)
#       elif len(container) == 1 and container[0] != string:
#           end_time = time.time()
#           print("Not Found In Tuple")
#           print("Time Delta", end_time - begin_time)
#           return -1
#
#    print("do stuff")


# Make binary search function that takes the tuple and string
def binary_search(container, string):
    print("Binary search for: ", string)
    begin_time = time.time()
    print("Beginning time", begin_time)
    low_bound = 0
    high_bound = len(container) - 1

    # loops until low_bound less than or equal to highbound
    while low_bound <= high_bound:
        # print(low_bound,high_bound)
        # finds the middle by taking average floored
        middle = (high_bound + low_bound) // 2

        # Compares the middle with string
        if container[middle] == string:
            # returns middle when found!!
            end_time = time.time()
            # print("Time Delta", end_time - begin_time)
            print("Found in Tuple")
            print("Time Delta", end_time - begin_time)
            return middle
        elif container[middle] < string:
            # Update lower_bound to middle + 1 if string is larger than middle
            low_bound = middle + 1
        else:
            # Update high_bound to middle - 1 if target is smaller
            high_bound = middle - 1

    # Return -1 if we don't find the string in the tuple
    end_time = time.time()
    print("Not Found In Tuple")
    print("Time Delta", end_time - begin_time)
    return -1


def main():
    a = get_data()
    print("data got")
    print(linear_search(a, "not_here"))
    print(binary_search(a, "not_here"))
    print("")
    print(linear_search(a, "mzzzz"))
    print(binary_search(a, "mzzzz"))
    print("")
    print(linear_search(a, "aaaaa"))
    print(binary_search(a, "aaaaa"))


if __name__ == '__main__':
    main()
