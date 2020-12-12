# WHAT IS fuckme
This is my attempt at a comprehensive unit tester for the libft project.
It's also my first attempt at any type of unit tester so... yeah

# WHY fuckme
Dude, why not. I'm trying to make the tests reaaally exhaustive so you will be prepared for a proper fucking from Moulinette. There are some things that I want to include or fix at a later stage, like:

- all functions. Some functions from part 1 are not included yet.
- bonus functions.
- some tests are supposed to segfault in part 1, currently fuckme doesn't check for that.
- adding different degrees so you can choose whether you want to be fucked gently, hard, or sideways.
- the shell script is flaky as fuck that shit is not reliable at all, I definitely want to improve it. Or just generally make it not suck.

# HOW TO fuckme
## Criterion
You will need to have Criterion installed (https://github.com/Snaipe/Criterion).
If you are trying to install Criterion from Codam, you might run into a problem installing Homebrew. Use the bot 'Le Gardien' and give it the command !brew to get more information on how to install.

## Where to copy libft folder
The default path to your libft is set to ./libft - meaning that fuckme will search the current directory for a subdirectory called 'libft' and use the contents of that directory. If you want to change the path you can do so in config.sh. But please don't cause I am actually not sure the tests will still run. Just make a subdirectory libft OK, please just do that.

If the config file points to your libft folder, execute the test script with ./fuckme.sh.
Executing the test script will compile your libft using your Makefile and then run the tests set out in fuckme.c. 

# HOW TO handle test results
## Missing Makefile
Either your Makefile is not named 'Makefile' or the path set out in config.sh is not correct. Or, you know, it's something else, in which case I dunno you will have to figure it out yourself or use a tester that was made by somebody who knows what they're doing.

## KOs
Most KOs will be accompanied by the following information. 

### Which tests produced a KO
Tests are organized as such: part_number, ft_name. This information is provided by criterion itself and will be displayed like this, or something like this:

[FAIL]	PART#::ft_name:

This tells you the test that produced a KO belongs to a function from part #, the function being ft_name.

! some functions, like ft_split and ft_substr, are open to interpretation, for example on how to handle NULL parameters. You might get a KO because your interpretation is different from mine. I think I specified this for every test that is open to interpretation, but just to be sure do keep this in mind.

### The exact line of code responsible for a KO
If a test fails - if it KOs - criterion will show not only FAIL but also the exact line of code that prompted this, like so:

fuckme.c:line #: Assertion failed: 'extra information'.

Line # will be the line of code in fuckme.c where the result from your function is compared with the expected result. For most tests, I include enough information for you not to have to check out the actual code in fuckme.c, not because I want to spare you the trouble but because I don't want you looking at it if I can help it.

### Extra information, possibly even in -->colour<--.
If there's extra information included, it will be printed right below the line that specifies the exact line of code responsible for a KO. This extra information will be, usually:
- what function KOd.
- which test for that function resulted in KO.
- extra information about that test.

If the extra information specifies 'KO on return value', this literally means that whatever is specified in the man as return value is not being returned. If the extra information specifies 'KO on destination string/concatenated string/whatever string', this means that you are not copying like the original function does. It's possible to pass a test on return value but KO on what kind of string it produces: for ft_strlcat for instance, your function should concatenate a string like strlcat does ánd return the same value that strlcat does. It is possible to do one, but not the other. 

# HOW TO handle errors in the script
I don't know man I barely understand how this script even works, I just combined enough stuff I found on the internet until I had a semi-functional script. If you encounter an error you will have to solve it yourself or come back in a year and hope my skills have improved significantly.
