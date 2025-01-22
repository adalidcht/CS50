#include <cs50.h>
#include <stdio.h>

void luhn_algorithm(long ccnumber);
int card_len(long ccnumber);
void card_validation(long sum, long ccnumber);
void card_company(long ccnumber);

int main(void)
{

    long card_number;
    int cc_len;

    card_number = get_long("Credit Card Number: ");

    cc_len = card_len(card_number);

    if (cc_len < 13 || cc_len > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        luhn_algorithm(card_number);
    }
}

int card_len(long ccnumber)
{
    int length = 0;
    while (ccnumber > 0)
    {
        ccnumber = ccnumber / 10;
        length++;
    }

    return length;
}

void luhn_algorithm(long ccnumber)
{
    long temp_ccnumber = ccnumber;
    int digit;
    int count = 0;
    long doubled = 0;
    long total_sum = 0;

    while (temp_ccnumber > 0)
    {
        digit = temp_ccnumber % 10;
        count++;
        temp_ccnumber = temp_ccnumber / 10;

        if (count % 2 == 0)
        {
            doubled = digit * 2;

            if (doubled > 9)
            {
                total_sum += (doubled % 10) + (doubled / 10);
            }
            else
            {
                total_sum += doubled;
            }
        }
        else
        {
            total_sum += digit;
        }
    }
    card_validation(total_sum, ccnumber);
}

void card_validation(long sum, long ccnumber)
{
    if (sum % 10 == 0)
    {
        card_company(ccnumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

void card_company(long ccnumber)
{
    int cc_len = card_len(ccnumber);

    while (ccnumber >= 100)
    {
        ccnumber = ccnumber / 10;
    }

    if ((cc_len == 13 || cc_len == 16) && (ccnumber >= 40 && ccnumber < 50))
    {
        printf("VISA\n");
    }
    else if (cc_len == 15 && (ccnumber == 34 || ccnumber == 37))
    {
        printf("AMEX\n");
    }
    else if (cc_len == 16 && (ccnumber >= 51 && ccnumber < 56))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
