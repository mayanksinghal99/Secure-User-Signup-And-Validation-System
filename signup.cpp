// Test cases for signup page
#include "test.h"
#include <iostream>
#include <cstring>

struct det
{
    char uname[50];
    int age;
    char password[100];
    char email[100];
    char mobile[10];
};

char temp_name[100], temp_password1[100];
char temp_password2[100], temp_email[100];
char temp_mobile[100];
int temp_age;

int count, success, j;
det s[100];

UNIT_TEST(Signup_TEST)
{
    std::cout << "\n\n";
    std::cout << "\n\tEnter Your name : ";
    std::cin >> temp_name;
    std::cout << "\tEnter Your Email : ";
    std::cin >> temp_email;
    std::cout << "\tEnter Password : ";
    std::cin >> temp_password1;
    std::cout << "\tConfirm Password : ";
    std::cin >> temp_password2;
    std::cout << "\tEnter Your Mobile Number : ";
    std::cin >> temp_mobile;
    std::cout << "\tEnter Your Age : ";
    std::cin >> temp_age;
    int i = 0, flag = 1;
    int check = 0;
    do
    {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z') || (temp_name[i] >= 'A' && temp_name[i] <= 'Z')))
        {
            flag = 0;
            break;
        }
        i = i + 1;
    } while (temp_name[i] != '\0');
    if (flag == 1)
    {
        check++;
        std::cout << "Test for name		 : ";
        test_assert(true);
    }
    else
    {
        std::cout << "Test for name		 : ";
        test_assert(false);
    }

    count = 0;
    i = 0;
    do
    {
        if (temp_email[i] == '@' || temp_email[i] == '.')
        {
            count++;
        }
        i = i + 1;
    } while (temp_email[i] != '\0');
    if (count >= 2 && strlen(temp_email) >= 5)
    {
        check++;
        std::cout << "Test for email		 : ";
        test_assert(true);
    }
    else
    {
        std::cout << "Test for email		 : ";
        test_assert(false);
    }

    if (!strcmp(temp_password1, temp_password2))
    {
        check++;
        std::cout << "Test for password match : ";
        test_assert(true);
    }
    else
    {
        std::cout << "Test for password match : ";
        test_assert(false);
    }

    if (strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12)
    {
        check++;
        std::cout << "Test for password length : ";
        test_assert(true);
    }
    else
    {
        std::cout << "Test for password length : ";
        test_assert(false);
    }
    if (strlen(temp_password1) >= 8 && strlen(temp_password1) <= 12)
    {
        int caps = 0;
        int Small = 0;
        int numbers = 0;
        int special = 0;
        i = 0;
        do
        {
            if (temp_password1[i] >= 'A' && temp_password1[i] <= 'Z')
            {
                caps = caps + 1;
            }
            else if (temp_password1[i] >= 'a' && temp_password1[i] <= 'z')
            {
                Small = Small + 1;
            }
            else if (temp_password1[i] >= '0' && temp_password1[i] <= '9')
            {
                numbers = numbers + 1;
            }
            else if (temp_password1[i] == '@' || temp_password1[i] == '&' || temp_password1[i] == '#' || temp_password1[i] == '*')
            {
                special = special + 1;
            }
            i = i + 1;
        } while (temp_password1[i] != '\0');
        if (caps >= 1 && Small >= 1 && numbers >= 1 && special >= 1)
        {
            check++;
            std::cout << "Test for password strength : ";
            test_assert(true);
        }
        else
        {
            std::cout << "Test for password strength : ";
            test_assert(false);
        }
    }

    if (temp_age > 0)
    {
        check++;
        std::cout << "Test for age		 : ";
        test_assert(true);
    }
    else
    {
        std::cout << "Test for age		 : ";
        test_assert(false);
    }
    if (strlen(temp_mobile) == 10)
    {
        i = 0;
        success = 0;
        do
        {
            if (temp_mobile[i] >= '0' && temp_mobile[i] <= '9')
            {
                success = 1;
            }
            else
            {
                break;
            }
            i = i + 1;
        } while (i < 10);
        if (success == 1)
        {
            check++;
            std::cout << "Test for mobile number	 : ";
            test_assert(true);
        }
        else
        {
            std::cout << "Test for mobile number	 : ";
            test_assert(false);
        }
    }
    else
    {
        std::cout << "Test for mobile number	 : ";
        test_assert(false);
    }
    i = 0;

    do
    {
        if (!(strcmp(temp_email, s[i].email) && strcmp(temp_password1, s[i].password)))
        {
            std::cout << "\n\n\tAccount Already Existed. Please "
                         "Login !!\n\n";
            flag = 0;
            break;
        }
        i = i + 1;
    } while (i < 100);
    if (check == 7)
    {
        strcpy(s[j].uname, temp_name);
        s[j].age = temp_age;
        strcpy(s[j].password, temp_password1);
        strcpy(s[j].email, temp_email);
        strcpy(s[j].mobile, temp_mobile);
        j++;
        std::cout << "All test case		 : ";
        test_assert(true);
        std::cout << "\n\n\tAccount Successfully Created!!\n\n";
    }
    else
    {
        std::cout << "\n\n\tOop something is wrong !!\n\n";
    }
    std::cout << "\n\n";
}
