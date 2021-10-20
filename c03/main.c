#include <stdio.h>
#include <string.h>

int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main()
{
	printf("%d\n", ft_strcmp("holza", "holaaa"));
	printf("%d\n", strcmp("holza", "holaaa"));
	
	printf("%d\n", ft_strncmp("ho", "holz", 2));
	printf("%d\n", strncmp("ho", "holz", 2));

	char str1[1000] = "";
	printf("%s\n", ft_strcat(str1, "hozaa"));
	printf("%s\n", ft_strcat(str1, "fff"));
	char str1_[1000] = "";
	printf("%s\n", strcat(str1_, "hozaa"));
	printf("%s\n", strcat(str1_, "fff"));
	
	char str2[1000] = "holabuenas";
	printf("%s\n", ft_strncat(str2, "hozaa", 2));
	printf("%s\n", ft_strncat(str2, "fff", 10));
	char str2_[1000] = "holabuenas";
	printf("%s\n", strncat(str2_, "hozaa", 2));
	printf("%s\n", strncat(str2_, "fff", 10));

	printf("%s\n", ft_strstr("ffff", "fff"));
	printf("%s\n", ft_strstr("ffff", ""));
	printf("%s\n", ft_strstr("", ""));
	printf("%s\n", ft_strstr("", "ff"));
	printf("%s\n", ft_strstr("ababcdab", "abc"));
	printf("%s\n", ft_strstr("ababcdab", "ab"));
	printf("%s\n", ft_strstr("abcababcddab", "abcd"));
	printf("%s\n", ft_strstr("abcabaabcddab", "abcd"));
	printf("%s\n", ft_strstr("abcababcddab", "abab"));
	
	printf("%s\n", strstr("ffff", "fff"));
	printf("%s\n", strstr("ffff", ""));
	printf("%s\n", strstr("", ""));
	printf("%s\n", strstr("", "ff"));
	printf("%s\n", strstr("ababcdab", "abc"));
	printf("%s\n", strstr("ababcdab", "ab"));
	printf("%s\n", strstr("abcababcddab", "abcd"));
	printf("%s\n", strstr("abcabaabcddab", "abcd"));
	printf("%s\n", strstr("abcababcddab", "abab"));

	printf("\n");

	char str3[1000] = "";
	printf("%d\n", ft_strlcat(str3, "bla", 3));
	printf("%s\n", str3);
	printf("%d\n", ft_strlcat(str3, "fff", 7));
	printf("%s\n", str3);
	printf("%d\n", ft_strlcat(str3, "asdf", 1));
	printf("%s\n", str3);
	printf("\n");
	char str3_[1000] = "";
	printf("%li\n", strlcat(str3_, "bla", 3));
	printf("%s\n", str3_);
	printf("%li\n", strlcat(str3_, "fff", 7));
	printf("%s\n", str3_);
	printf("%li\n", strlcat(str3_, "asdf", 1));
	printf("%s\n", str3_);

	return (0);
}
