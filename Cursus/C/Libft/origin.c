
#include "libft.h"

size_t	strlcat(char *dest, char *src, size_t size)
{
	size_t	count_1;
	size_t	count_2;

	count_1 = 0;
	count_2 = 0;
	while (dest[count_1] != '\0' && count_1 < size)
		count_1++;
	while (src[count_2] != '\0' && count_1 + count_2 + 1 < size)
	{
		dest[count_1 + count_2] = src[count_2];
		count_2++;
	}
	if (count_1 < size)
		dest[count_1 + count_2] = '\0';
	while (src[count_2] != '\0')
		count_2++;
	return (count_1 + count_2);
}

size_t strlcpy(char *dst, const char *src, size_t dstsize) {
    size_t src_len = strlen(src);

    if (dstsize > 0) {
        size_t copy_len = (src_len >= dstsize) ? dstsize - 1 : src_len;
        strncpy(dst, src, copy_len);
        dst[copy_len] = '\0';
    }

    return src_len;
}

char *strnstr(const char *haystack, const char *needle, size_t len) {
    size_t needle_len = strlen(needle);
    if (needle_len == 0) {
        return (char *)haystack;
    }

    for (size_t i = 0; i + needle_len <= len && haystack[i] != '\0'; i++) {
        if (strncmp(&haystack[i], needle, needle_len) == 0) {
            return (char *)&haystack[i];
        }
    }

    return NULL;
}

// Adicionales
char	*substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (!s || (!(str = malloc(len + 1))))
		return (NULL);
	if (start > ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	while (len--)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	if (!(str = malloc((a + b + 1))) || !str)
		return (NULL);
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	return (str);
}

int		flag_guessing(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i])
		if (s1[i++] == c)
			return (1);
	return (0);
}

char	*strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*new;
	size_t	len;
	size_t	k;

	i = 0;
	k = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	while (flag_guessing(set, s1[i]) && s1[i])
		i++;
	while (flag_guessing(set, s1[len - 1]) && (len - 1))
		len--;
	if (len < i)
		len = i;
	new = malloc(len - i + 1);
	if (!new)
		return (NULL);
	while (i < len)
		new[k++] = s1[i++];
	new[k] = '\0';
	return (new);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**split(char const *s, char c)
{
    int		i;
    int		j;
    int		k;
    char	**result;

    result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    if (!s || !result)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
        if (s[i] != c)
        {
            k = 0;
            while (s[i + k] && s[i + k] != c)
                k++;
            result[j] = ft_substr(s, i, k);
            j++;
            i += k;
        }
        else
            i++;
    result[j] = NULL;
    return (result);
}

void free_split(char **split_result) {
    if (!split_result) return;
    for (int i = 0; split_result[i]; i++) {
        free(split_result[i]);
    }
    free(split_result);
}
