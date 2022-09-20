#include <stdio.h>
#include <cs50.h>

void atm_menu(void);

// Simple ATM Machine System by Mohamed Mostafa

int main(void)
{
    int select;int rerun;
    printf("\t\t------------------------------------------------------------------------------------------------------");
    printf("\n\t\t|\t\t\t\t\tValar ATM\t\t\t\t\t\t     |\n");
    printf("\t\t------------------------------------------------------------------------------------------------------");
    printf("\n\n\n(1) Start\n\n(2) Exit");

    do
    {

        select = get_int("\n\n(*) Select: ");
        if(select == 1)
        {
            atm_menu();
        }
        else if(select == 2)
        {
            printf("\n(!) Valar ATM Stopped.\n\n");
            return 1;
        }
    }while(select < 1 || select > 2);

}

void atm_menu(void)
{
    int balance = 30000;int deposit;int withdraw;int selection;int dep_prompt;int money_c;int run;int pass = 1515;
    int pr;int with_prompt;
    printf("\n\n----------------------------------------------------");
    printf("\n| Valar ATM Management Menu \t\t\t   |");
    printf("\n----------------------------------------------------\n");
    printf("\n(1) Check Balance.\n\n(2) Deposit.\n\n(3) Withdraw.\n\n");

    do
    {
        selection = get_int("\n(*) Choose From Menu: ");}while(selection < 1 || selection > 3);
        if(selection == 1)
        {
            printf("\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
            printf("\n$ (-) Balance: %i%s%s\n",balance,"$","\t\t    $");
            printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");

            do
            {
                run = get_int("\n(-) Enter 0 To Back To Menu: ");
                if(run == 0)
                {
                    atm_menu();
                }
            }while(run > 0 || run < 0);

        }
        else if(selection == 2)
        {
            dep_prompt = get_int("\n($) Enter Deposit Amount: ");
            if(dep_prompt > 25000)
            {
                printf("\n--------------------------------------------------");
                printf("\n|($) Sorry, The Maximum Deposit Amount is 25000$.|");
                printf("\n--------------------------------------------------");

            }
            else
            {
                printf("\n($) Please Put The Money Into The Machine, Type (1) To Confirm Or (0) To Cancel.\n");
                do
                {
                    pr = get_int("\n(?) Choose: ");
                        if(pr == 1)
                        {
                            money_c = get_int("\n(?) Confirm Your Password: ");
                            if(money_c == pass)
                            {
                                balance += dep_prompt;
                                printf("\n-------------------------------------------------------------------------------------------------");
                                printf("\n| ($) Deposit Successfully Added To Your Account, Your Current Balance is: %i%s",balance,"$\t\t|");
                                printf("\n-------------------------------------------------------------------------------------------------");

                            }
                            else
                            {
                                printf("\n--------------------------");
                                printf("\n| (!) Incorrect Password.|\n");
                                printf("--------------------------");

                            }
                        }
                        else if(pr == 0)
                        {
                            atm_menu();
                        }
                }while(pr < 0 || pr > 1);
            }
                int x = get_int("\n\n(1) Back\n\n(0) Exit\n\n(*) Select: ");
                if(x == 0)
                {
                    printf("\n(!) Valar ATM Stopped.\n\n");
                }
                else if(x == 1)
                {
                    main();
                }
                 else
                {
                    printf("\n(x) Error, Invalid Selection.\n\n");
                }
        }
        else if(selection == 3)
        {
            with_prompt = get_int("\n($) Enter Withdraw Amount: ");
            if(with_prompt > 40000)
            {
                printf("\n--------------------------------------------------");
                printf("\n|($) Sorry, The Maximum Withdraw Amount is 40000$|");
                printf("\n--------------------------------------------------");

            }
            else
            {
                printf("\n($) Please Confirm Withdraw, Type (1) To Confirm Or (0) To Cancel.\n");
                do
                {
                    pr = get_int("\n(?) Choose: ");
                    if(pr == 1)
                    {
                        money_c = get_int("\n(?) Confirm Your Password: ");
                        if(money_c == pass && with_prompt <= balance)
                        {
                            balance -= with_prompt;
                            printf("\n------------------------------------------------------------------------------------------------------------------");
                            printf("\n($) Withdraw Successfully Done, The Money Is Coming Out In A Sec \n\n[$] Your Current Balance is: %i%s",balance,"$\n");
                            printf("------------------------------------------------------------------------------------------------------------------");

                        }
                        else if(money_c == pass && with_prompt > balance)
                        {
                            printf("\n---------------------------------------------");
                            printf("\n| ($) Withdraw Failed, Insufficient Balance.|");
                            printf("\n---------------------------------------------");

                        }
                        else
                        {
                            printf("\n--------------------------");
                            printf("\n| (!) Incorrect Password.|\n");
                            printf("--------------------------");
                        }
                    }
                    else if(pr == 0)
                    {
                            atm_menu();
                    }
                }while(pr < 0 || pr > 1);
            }
            int x = get_int("\n\n(1) Back\n\n(0) Exit\n\n(*) Select: ");
            if(x == 0)
            {
                printf("\n(!) Valar ATM Stopped.\n\n");
            }
            else if(x == 1)
            {
                main();
            }
            else
            {
                printf("\n(x) Error, Invalid Selection.\n\n");
            }
        }
}
