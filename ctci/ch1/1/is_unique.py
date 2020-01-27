def is_unique (test_string: str) -> bool:
    charset = set();
    for s in test_string:
        if s in charset:
            return False
        else:
            charset.add(s)
    return True

print(is_unique("foobar"))
print(is_unique("abcde"))
print(is_unique(""))
print(is_unique("123456"))

def is_unique_no_data(test_string: str) -> bool:
    for i in range(len(test_string)):
        for j in range(i+1, len(test_string)):
            if test_string[i] == test_string[j]:
                return False
    return True

print(is_unique_no_data("foobar"))
print(is_unique_no_data("abcde"))
print(is_unique_no_data(""))
print(is_unique_no_data("123456"))
