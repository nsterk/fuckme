# WHAT IS fuckme
This is my attempt at a comprehensive unit tester for the libft project.
It's also my first attempt at any type of unit tester so... yeah


# HOW TO fuckme
The default path to your libft is set as ./libft - meaning that fuckme will search the current directory for a subdirectory called 'libft' and use the contents of that directory. If you want to change the path you can do so in config.sh

If the config file points to your libft folder, execute the test script with ./fuckme.sh

Executing the test script will compile your libft using your Makefile and then run the tests set out in fuckme.c. 


# HOW TO handle test results
## missing Makefile
Either your Makefile is not named 'Makefile' or the path set out in config.sh is not correct. Or, you know, it's something else, in which case I dunno you will have to figure it out yourself or use a tester that was made by somebody who knows what they're doing.

## KOs
KOs are semi structured. Most KOs will be accompanied by the following information: 

### which tests produced a KO
Tests are organized as such: part_number, ft_name. This information is provided by criterion itself and will be displayed like this, or something like this:

[FAIL]	PART#::ft_name:
This tells you the test that produced a KO belongs to a function from part #, the function being ft_name.

### the exact line of code responsible for a KO
If a test fails - if it KOs - criterion will show not only FAIL but also the exact line of code that prompted this, like so:

fuckme.c:line #: Assertion failed: 'extra information'

Line # will be the line of code in fuckme.c where the result from your function is compared with the expected result. For most tests, I include enough information for you not to have to check out the actual code in fuckme.c, not because I want to spare you the trouble but because I don't want you looking at it if I can help it.

### extra information, possibly even in **colour**
If there's extra information included, it will be printed right below the line that specifies the exact line of code responsible for a KO. This extra information will be, usually:
- what function KOd
- which test for that function resulted in KO
- extra information about that test


# HOW TO handle errors in the script
I don't know man I barely understand how this script even works, I just combined enough stuff I found on the internet until I had a semi-functional script. If you encounter an error you will have to solve it yourself or come back in a year and hope my skills have improved significantly.
