/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fuckme.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nsterk <nsterk@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 20:00:47 by nsterk        #+#    #+#                 */
/*   Updated: 2020/11/14 23:18:52 by nsterk        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <limits.h>
#include <stdlib.h>

/******************************************************************************/
/*									  PART 1								  */
/******************************************************************************/

/*	FT_ISALNUM	*/
Test(PART1, ft_isalnum)
{
	cr_expect_eq(ft_isalnum('9'), isalnum('9'));
	cr_expect_eq(ft_isalnum('?'), isalnum('?'));
	cr_expect_eq(ft_isalnum('a'), isalnum('a'));
	cr_expect_eq(ft_isalnum('0'), isalnum('0'));
	cr_expect_eq(ft_isalnum('z'), isalnum('z'));
	cr_expect_eq(ft_isalnum('{'), isalnum('{'));
}
/*	FT_ISALPHA	*/
Test(PART1, ft_isalpha)
{
	cr_expect_eq(ft_isalpha('9'), isalpha('9'));
	cr_expect_eq(ft_isalpha('?'), isalpha('?'));
	cr_expect_eq(ft_isalpha('a'), isalpha('a'));
	cr_expect_eq(ft_isalpha('0'), isalpha('0'));
	cr_expect_eq(ft_isalpha('z'), isalpha('z'));
	cr_expect_eq(ft_isalpha('{'), isalpha('{'));
}
/*	FT_ISASCII	*/
Test(PART1, ft_isascii)
{
	cr_expect_eq(ft_isascii(-5), isascii(-5));
	cr_expect_eq(ft_isascii('?'), isascii('?'));
	cr_expect_eq(ft_isascii(200), isascii(200));
	cr_expect_eq(ft_isascii('0'), isascii('0'));
	cr_expect_eq(ft_isascii(128), isascii(128));
	cr_expect_eq(ft_isascii('{'), isascii('{'));
}
/*	FT_ISDIGIT	*/
Test(PART1, ft_isdigit)
{
	cr_expect_eq(ft_isdigit('0'), isdigit('0'));
	cr_expect_eq(ft_isdigit(0), isdigit(0));
	cr_expect_eq(ft_isdigit('9'), isdigit('9'));
	cr_expect_eq(ft_isdigit('5'), isdigit('5'));
}
/*	FT_ISPRINT	*/
Test(PART1, ft_isprint)
{
	cr_expect_eq(ft_isprint(31), isprint(31));
	cr_expect_eq(ft_isprint(32), isprint(32));
	cr_expect_eq(ft_isprint(127), isprint(127));
	cr_expect_eq(ft_isprint(126), isprint(126));
}
/*	FT_STRLCAT	*/
Test(PART1, ft_strlcat)
{
	char	src[] = "de bomdiggy";
	char	dest[100] = "momo is ";
	char	dest2[100] = "momo is ";
	//test 1
	cr_expect_eq(ft_strlcat(dest, src, 20), strlcat(dest2, src, 20), "[1] KO on return value");
	ft_strlcat(dest, src, 20);
	strlcat(dest2, src, 20);
	cr_expect_str_eq(dest, dest2, "[1] KO on concatenated string");
	//test 2
	cr_expect_eq(ft_strlcat(dest, src, 10), strlcat(dest2, src, 10), "[2] KO on return value for size < strlen dest");
	ft_strlcat(dest, src, 10);
	strlcat(dest2, src, 10);
	cr_expect_str_eq(dest, dest2, "[2] KO on concatenated string value for size < strlen dest");
	//test 3
	cr_expect_eq(ft_strlcat(dest, src, 0), strlcat(dest2, src, 0), "[3] KO on return value for size = 0");
	ft_strlcat(dest, src, 0);
	strlcat(dest2, src, 0);
	cr_expect_str_eq(dest, dest2, "[3] KO on concatenated string for size = 0\n");
}
/*	FT_MEMCPY	*/
Test(PART1, ft_memcpy)
{	
	//test 1 this sucks i got stuck because my own ft_memcpy was failing and i still dont get it im sick of this test so moving forward
	// oh my god i was testing it with cr_expect_eq instead of cr_expect_str_eq fuck me 
	// fucking hell
	char dst1[50] = "aaaaaaaaaaaaaaaaaaaaaaa";
	char dst11[50] = "aaaaaaaaaaaaaaaaaaaaaaa";
	const char src[] = "bbbbbbbbbbb";
	char *ptr;
	char *ptr2;
	ptr2 = memcpy(dst1, src, 5);
	ptr = ft_memcpy(dst11, src, 5);
	cr_expect_str_eq(ptr, ptr2, "[1] KO");
}
/*	FT_MEMCCPY	*/
Test(PART1, ft_memccpy)
{	
	//i know this is really ugly
	//test 1
	const char src[] = "yummy yummy yummy food in naomi's tummy";
	char dst1[50] = "                                       ";
	cr_expect_null(ft_memccpy(dst1, src, 'f', 5), "[1] KO");
	//test 2
	char dst2[50] = "                                       ";
	char dst22[50] = "                                       ";
	cr_expect_str_eq(ft_memccpy(dst2, src, 'f', 40), memccpy(dst22, src, 'f', 40), "[2] KO");

}
/*	FT_MEMSET	*/
Test(PART_1, ft_memset)
{
	char expected[] = "supercalifragilisticexpialidocious";
	char returned[] = "supercalifragilisticexpialidocious";
	int c = 'x';
	
	//test 1
	memset(expected, c, 0);
	ft_memset(returned, c, 0);
	cr_expect_str_eq(expected, returned);
	//test 2
	memset(expected, c, 5);
	ft_memset(returned, c, 5);
	cr_expect_str_eq(expected, returned);
}
/*	FT_MEMCHR	*/
Test(PART_1, ft_memchr)
{
	char	*s;
	void	*expected;
	void	*returned;
	//test 1
	s = "Search this string!! for char";
	expected = memchr(s, 'a', 20);
	returned = ft_memchr(s, 'a', 20);
	cr_expect_str_eq(expected, returned);
	//test 2
	s = "Search this string!! for char";
	expected = memchr(s, '!', 30);
	returned = ft_memchr(s, '!', 30);
	cr_expect_str_eq(expected, returned);
	//test 3
	s = "Search this string!! for char";
	expected = memchr(s, '?', 30);
	returned = ft_memchr(s, '?', 30);
	cr_expect_null(returned);
	//test 4
	s = "Search this string!! for char";
	expected = memchr(s, '\0', 100);
	returned = ft_memchr(s, '\0', 100);
	cr_expect_str_eq(expected, returned);
}
/*	FT_STRNSTR	*/
Test(PART1, ft_strnstr)
{
	char	*haystack;
	char	*needle;
	size_t	len;
	//test 1: len 18 is just enough to find needle so should return (moppie)
	haystack = "momo is een moppie";
	needle = "moppie";
	len = 18;
	cr_expect_str_eq(ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len), "[1] KO");
	//test 2: len 17 just falls short of returning needle so should return (null)
	haystack = "momo is een moppie";
	needle = "moppie";
	len = 17;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[2] KO");
	//test 3: do you ignore characters after a '\0'?
	haystack = "momo is een \0moppie";
	needle = "moppie";
	len = 20;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[3] KO");
	//test 4: string contains part of needle (want) but not the entire thing (wanted)
	haystack = "I'll tell you what I want what I really really want";
	needle = "wanted";
	len = 60;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[4] KO");
	//test 5: len = 0, should return (null)
	haystack = "despite donald sutherland being a sexy beast in eye of the needle, the book was better than the film";
	needle = "the film rushed through the first half of the book";
	len = 0;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[5] KO");
	//test 6: needle is empty string, should return haystack
	haystack = "despite donald sutherland being a sexy beast in eye of the needle, the book was better than the film";
	needle = "";
	len = 50;
	cr_expect_str_eq(ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len), "[6] KO");
	//test 7: haystack is empty string, should return (null)
	haystack = "";
	needle = "and then spent waaaay too much time going over the island part";
	len = 0;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[7] KO");
	//test 8: ft_strnstr ALMOST found needle. but it didn't, so should return (null)
	haystack = " it to  the it        it just felt rushe";
	needle = "it just felt rushed";
	len = 50;
	cr_expect_null(ft_strnstr(haystack, needle, len), "[8] KO");
	//test 9: find abac in ababac: do you continue your search in the right place
	//								when a match turns out only to be a *partial* match
	haystack = "ababac";
	needle = "abac";
	len = 50;
	cr_expect_str_eq(ft_strnstr(haystack, needle, len), strnstr(haystack, needle, len), "[9] KO: Your ft_strnstr doesn't pick up search in the correct location if a match turns out to be only partial match\nTest: find \"abac\" in \"ababac\"");
}
/*	FT_TOUPPER	*/
Test(Part_1, ft_toupper)
{
	cr_expect_eq(toupper('&'), ft_toupper('&'));
	cr_expect_eq(toupper('A'), ft_toupper('A'));
	cr_expect_eq(toupper('a'), ft_toupper('a'));
}
/*	FT_TOLOWER	*/
Test(Part_1, ft_tolower)
{
	cr_expect_eq(tolower('&'), ft_tolower('&'));
	cr_expect_eq(tolower('A'), ft_tolower('A'));
	cr_expect_eq(tolower('a'), ft_tolower('a'));
}
/*	FT_ATOI		*/
Test(PART_1, ft_atoi)
{
	char *number_string;
	
	//test1
	number_string = "---1234";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test2
	number_string = "   \f\v\r\v -2147483648";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test3
	number_string = "   \f\v\r\v -2147483\v648";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test3
	number_string = "-+2147483648";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test4
	number_string = "-2147483680";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test5
	number_string = "   00000";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test6
	number_string = " +99";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
	//test7
	number_string = "-2147483647";
	cr_expect_eq(atoi(number_string), ft_atoi(number_string));
}

/******************************************************************************/
/*									  PART 2								  */
/******************************************************************************/

/*		FT_SPLIT		*/
//static functions to check if returned arrays match expected arrays, print
//results and free allocated memory
static size_t		check_split(char **str, char **expect)
{
	size_t i;

	i = 0;
	while (expect[i] != NULL)
	{
		if (!str[i])
			return (0);
		else if (strcmp(expect[i], str[i]))
			return (0);		
		i++;
	}
	if (str[i])
		return (0);
	return (1);
}
void			print_split(char **str, char **expected)
{
		size_t i;
		
		i = 0;
		printf("\033[4;37m");printf("Expected");printf("\033[0m: ");
		while (expected[i] != NULL)
		{
			printf("%zu: [%s]	", i, expected[i]);
			i++;
		}
		printf("%zu: [%s]\n", i, expected[i]);
		i = 0;
		printf("\033[4;37m");printf("Got");printf("\033[0m: 	  ");
		while (str[i] != NULL)
		{
			printf("%zu: [%s]	", i, str[i]);
			i++;
		}
		printf("%zu: [%s]\n", i, str[i]);
}
static void	*free_split(char **str)
{
	size_t i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	return (NULL);
}
//tests for ft_split
Test(PART_2, ft_split)
{
	char **str_split;
	char **expected;
	char *str_src;
	char delimiter;
	int len;
	int are_arrays_equal;
	//test 1 
	str_src = "_ab_cd_ef_";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[1] KO for 1 leading and 1 trailing delimiter");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 2
	str_src = "__ab_cd_ef___";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[2] KO for multiple leading and trailing delimiters");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 3
	str_src = "ab_cd_ef_";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[3] KO on 1 trailing delimiter");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 4
	str_src = "ab_cd_ef___";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[4] KO on multiple trailing delimiters");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 5
	str_src = "_ab_cd_ef";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[5] KO on 1 leading delimiter");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 6
	str_src = "___ab_cd_ef";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "ab";
	expected[1] = "cd";
	expected[2] = "ef";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[6] KO on multiple leading delimiters");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 7
	str_src = "abc__def____ghi";
	delimiter = '_';
	len = 3;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "abc";
	expected[1] = "def";
	expected[2] = "ghi";
	expected[3] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[7] KO on multiple delimiters in middle");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 8
	str_src = "aaaaaaaaaaaaaaaaaaaaaaaaa";
	delimiter = 'a';
	len = 0;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[8] KO on src being only delimiters");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 9
	str_src = "aaaaaaaaaaaaaaaaaaaaaaaaa";
	delimiter = '_';
	len = 1;
	str_split = ft_split(str_src, delimiter);
	expected = (char **)malloc(sizeof(char*) * (len + 1));
	expected[0] = "aaaaaaaaaaaaaaaaaaaaaaaaa";
	expected[1] = NULL;
	are_arrays_equal = check_split(expected, str_split);
	cr_expect(are_arrays_equal == 1, "[9] KO for src not containing delimiter (open to interpretation)");
	if (!are_arrays_equal)
	{
		printf("\e[0;35m");printf("	Src:");printf("\e[0m");printf(" [%s]  ", str_src);
		printf("\e[0;35m");printf("Delimiter: ");printf("\e[0m");printf("'_'\n");
		print_split(str_split, expected);
	}
	free(expected);
	free_split(str_split);
	//test 10 (open to interpretation)
	str_src = NULL;
	delimiter = '_';
	len = 1;
	str_split = ft_split(str_src, delimiter);
	cr_expect_null(str_split, "[10] KO for src being NULL (open to interpretation)");
	free_split(str_split);
}
/*		FT_SUBSTR		*/
Test(PART_2, ft_substr)
{
	char *src;
	char *expected;
	char *sub_str;
	unsigned int start;
	size_t len;
	//test1 basic input
	src = "hey yo captain jack";
	expected = "yo captain jack";
	start = 4;
	len = 30;
	sub_str = ft_substr(src, start, len);
	cr_expect_str_eq(sub_str, expected, "KO[1]	ft_substr(\"hey yo captain jack\", 4, 30);\nExpected: [%s]\nGot: [%s]\n", expected, sub_str);
	if (sub_str)
		free(sub_str);
	//test2 - len < src length
	expected = "yo captain";
	start = 4;
	len = 10;
	sub_str = ft_substr(src, start, len);
	cr_expect_str_eq(sub_str, expected, "KO[2]	ft_substr(\"hey yo captain jack\", 4, 10);\nExpected: [%s]\nGot: [%s]\n", expected, sub_str);
	if (sub_str)
		free(sub_str);
	//test3 start > src length
	expected = "";
	start = 50;
	len = 10;
	sub_str = ft_substr(src, start, len);
	cr_expect_str_eq(sub_str, expected,"ft_substr test 3: start > source length\nExpected: [%s]\nGot: [%s]\n", expected, sub_str);
	if (sub_str)
		free(sub_str);
	//test4 src = NULL
	start = 50;
	len = 10;
	sub_str = ft_substr(NULL, start, len);
	cr_expect_null(sub_str, "ft_substr test 4: src is NULL\nExpected: [(null)]\nGot: [%s]\n", sub_str);
	if (sub_str)
		free(sub_str);
	//test5 len = 0 (open to interpretation I guess)
	start = 0;
	len = 0;
	sub_str = ft_substr(src, start, len);
	cr_expect_str_eq(sub_str, expected, "ft_substr test 5\nlen is 0\nExpected: [%s]\nGot: [%s]\n", expected, sub_str);
	if (sub_str)
		free(sub_str);
}
/*		FT_STRJOIN		*/
Test(PART_2, ft_strjoin)
{
	char *s1;
	char *s2;
	char *result;
	char *expected;

	//test 1
	s1 = "ik heb een toe toe toeter ";
	s2 = "maar geen waterscooter";
	expected = "ik heb een toe toe toeter maar geen waterscooter";
	result = ft_strjoin(s1, s2);
	cr_expect_str_eq(expected, result,"ft_strjoin test 1\ns1 is [ik heb een toe toe toeter], s2 is [maar geen waterscooter]\nExpected: [%s]\nGot: [%s]\n", expected, result);
	if (result)
		free(result);
	//test 2
	s1 = NULL;
	s2 = "maar geen waterscooter";
	expected = NULL;
	result = ft_strjoin(s1, s2);
	cr_expect_null(result, "ft_strjoin test 2\ns1 is NULL, s2 is [maar geen waterscooter]\nExpected: [%s]\nGot: [%s]\n", expected, result);
	if (result)
		free(result);
	//test 3
	s1 = "xyz";
	s2 = NULL;
	expected = NULL;
	result = ft_strjoin(s1, s2);
	cr_expect_null(expected, "ft_strjoin test 3\ns1 is [xyz], s2 is NULL\nExpected: [%s]\nGot: [%s]\n", expected, result);
	if (result)
		free(result);
}
/*		FT_STRTRIM		*/
//static function to print results for ft_strim (in case of KO)
static 	void	print_trim(char *expected, char *result)
{
		printf("\033[4;37m");printf("Expected");printf("\033[0m");
		printf(":[%s]\n", expected);
		printf("\033[4;37m");printf("Got");printf("\033[0m");
		printf(":	 [%s]\n", result);
}
Test(PART_2, ft_strtrim)
{
	char *str;
	char *set;
	char *result;
	char *expected;

	//test 1
	str = "12abc123";
	set = "123456789";
	expected = "abc";
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 1\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s]", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 2
	str = "\n\f26 ";
	set = "\n\v\f\r\t ";
	expected = "26";
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 2\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[\\n\\f26 ]	");
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[\\n\\v\\f\\r\\t ]\n");
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 3: string only contains characters that need to be trimmed
	str = "aaaaaaaaaaa";
	set = "a";
	expected = "";
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 3\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 4: source only contains characters that need to be trimmed part 2
	str = "aaaaacaaaaaac";
	set = "abc";
	expected = "";
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 4\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 5: source does not contain characters that need to be trimmed
	str = "aaaaacaaaaaac";
	set = "12345";
	expected = str;
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 5\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 6: set is NULL pointer
	str = "aaaaaaaaaaa";
	set = NULL;
	expected = str;
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 6\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	if (result)
		free(result);
	//test 7: string is NULL pointer
	str = NULL;
	set = "not null";
	expected = NULL;
	result = ft_strtrim(str, set);
	cr_expect_null(expected, "ft_strtrim test 7\n");
	if (result)
		free(result);
	//test 8: string is empty
	str = "";
	set = "abcdefg";
	expected = str;
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 8\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
	//test 9: string contains all chars in set, but not at edges
	str = "aaaaaaabcdefgha";
	set = "bcdefg";
	expected = str;
	result = ft_strtrim(str, set);
	cr_expect_str_eq(expected, result,"ft_strtrim test 9\n");
	if (strcmp(result, expected))
	{
		printf("\e[0;35m");printf("	Src: ");printf("\e[0m");printf("[%s] ", str);
		printf("\e[0;35m");printf("Set: ");printf("\e[0m");printf("[%s]\n", set);
		print_trim(expected, result);
	}
}
/*		FT_STRMAPI		*/
//static function for ft_strmapi to receive
static char		testmapi(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}
//the one test I have for ft_strmapi
Test(PART_2, ft_strmapi)
{
	//test 1 
	//also only test
	cr_expect(ft_strncmp(ft_strmapi("momo", testmapi), "MOMO", 10) == 0, "KO ft_strmapi");
}
/*		FT_ITOA			*/
Test(PART_2, ft_itoa)
{
	char	expected[30];
	char	*returned;

	//test 1: exactly minimum int value. Using INT_MIN because min and max values may differ across operating systems
	returned = ft_itoa(INT_MIN);
	sprintf(expected, "%i", INT_MIN);
	cr_expect_str_eq(expected, returned, "ft_itoa test 1\n");
	if (strcmp(expected, returned)) //using function for print_trim b/c it's what I need and I'm too lazy to rename or change structure of this code right now
	{
		print_trim(expected, returned);
	}
	//test 2: exactly max int value
	returned = ft_itoa(INT_MAX);
	sprintf(expected, "%i", INT_MAX);
	cr_expect_str_eq(expected, returned, "ft_itoa test 2\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 3: zero
	returned = ft_itoa(0);
	sprintf(expected, "%i", 0);
	cr_expect_str_eq(expected, returned, "ft_itoa test 3\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 4: two signs
	returned = ft_itoa(+-99);
	sprintf(expected, "%i", +-99);
	cr_expect_str_eq(expected, returned, "ft_itoa test 4\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 5: two signs but turn it around
	returned = ft_itoa(-+99);
	sprintf(expected, "%i", -+99);
	cr_expect_str_eq(expected, returned, "ft_itoa test 5\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 6: start with a zero
	returned = ft_itoa(0123);
	sprintf(expected, "%i", 0123);
	cr_expect_str_eq(expected, returned, "ft_itoa test 6\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 7: end with a zero
	returned = ft_itoa(1230);
	sprintf(expected, "%i", 1230);
	cr_expect_str_eq(expected, returned, "ft_itoa test 7\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 8: an annnoying nmber of zeroes
	returned = ft_itoa(000000);
	sprintf(expected, "%i", 000000);
	cr_expect_str_eq(expected, returned, "ft_itoa test 8\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
	//test 9: an annnoying nmber of zeroes and an even more annoying non-zero in the middle
	returned = ft_itoa(0003000);
	sprintf(expected, "%i", 0003000);
	cr_expect_str_eq(expected, returned, "ft_itoa test 9\n");
	if (strcmp(expected, returned))
	{
		print_trim(expected, returned);
	}
}

