
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