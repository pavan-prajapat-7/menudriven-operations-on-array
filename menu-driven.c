#include <stdio.h>
#include <windows.h>
#include <unistd.h> // For sleep()
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

void loading()
{
    printf("Loading");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout); // Forces the output to display immediately
        sleep(1);       // Pause for 1 second
    }
    printf("\nDone!\n");
}

void playSound()
{
    for (int i = 0; i < 10; i++)
    {                                     // 10 beeps for the countdown
        int frequency = 1000 + (i * 300); // Increase frequency by 300Hz for each beep (1000Hz, 1300Hz, 1600Hz, etc.)
        int duration = 1000 - (i * 100);  // Decrease the duration (1000ms to 100ms)

        if (duration < 100)
        {
            duration = 100; // Ensure that duration doesn't go below 100ms
        }

        Beep(frequency, duration); // Play the beep sound
        Sleep(300);                // Short pause between beeps to increase urgency
    }
}

void yes()
{
    int x, insert, del, arr[100], pos, ele, n, i, item;
    do
    {

        printf(YELLOW "\n > Choose Your Action!!\n" RESET);
        printf(GREEN " [1] Insert a new element in the array\n" RESET);
        printf(RED " [2] Delete an element from the array\n" RESET);
        printf(" Select your move (1 or 2): ");
        scanf("%d", &x);

        if (x == 1)
        {
            printf(YELLOW "\nYou have chosen to insert a new element in the array.\n" RESET);
            printf(BLUE " [1] Insert an element at the beginning of the array\n" RESET);
            printf(BLUE " [2] Insert an element at the end of the array\n" RESET);
            printf(BLUE " [3] Insert an element at a particular position in the array\n" RESET);
            printf(" Select your operation >> ");
            scanf("%d", &insert);

            switch (insert)
            {
            case 1:
                printf(GREEN "\nInsertion at the beginning of the array.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                printf("Enter the element to be added: ");
                scanf("%d", &ele);
                for (i = n - 1; i >= 0; i--)
                {
                    arr[i + 1] = arr[i];
                }
                arr[0] = ele;
                n = n + 1;
                printf(BLUE "The array elements are: " RESET);
                for (i = 0; i < n; i++)
                {
                    printf("%5d", arr[i]);
                }

                break;

            case 2:
                printf(GREEN "\nInsertion at the end of the array.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                printf("Enter the element to be added: ");
                scanf("%d", &ele);
                arr[n] = ele;
                n++;

                printf(BLUE "The array after insertion: " RESET);
                for (i = 0; i < n; i++)
                {
                    printf("%d\t", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                printf(GREEN "\nInsertion at a particular position.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                printf("Enter the position: ");
                scanf("%d", &pos);
                if (pos < 0 || pos > n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    printf("Enter the element to be inserted: ");
                    scanf("%d", &ele);
                    for (i = n - 1; i >= pos; i--)
                    {
                        arr[i + 1] = arr[i];
                    }
                    arr[pos] = ele;
                    n++;

                    printf("Element %d is inserted at position %d\n", ele, pos);
                    printf(BLUE "Array after insertion: " RESET);
                    for (i = 0; i < n; i++)
                    {
                        printf("%d\t", arr[i]);
                    }
                    printf("\n");
                }
                break;

            default:
                printf("Invalid choice.\n");
                break;
            }
        }

        else if (x == 2)
        {
            printf(YELLOW "\nYou have chosen to delete an element from the array.\n" RESET);
            printf(RED " [1] Delete an element from the beginning of the array\n" RESET);
            printf(RED " [2] Delete an element from the end of the array\n" RESET);
            printf(RED " [3] Delete an element from a particular position in the array\n" RESET);
            printf(" Select your operation >> ");
            scanf("%d", &del);

            switch (del)
            {
            case 1:
                printf(YELLOW "\nDeletion of element at the beginning of the array.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                ele = arr[0];
                for (i = 0; i < n; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n = n - 1;
                printf(BLUE "Array after deletion: " RESET);
                for (i = 0; i < n; i++)
                {
                    printf("%5d", arr[i]);
                }

                break;

            case 2:
                printf(YELLOW "\nDeletion of element at the end of the array.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                ele = arr[n - 1];
                n = n - 1;
                printf("Element %d deleted from the array.\n", ele);
                printf(BLUE "Array after deletion: " RESET);
                for (i = 0; i < n; i++)
                {
                    printf("%5d", arr[i]);
                }
                break;

            case 3:
                printf(YELLOW "\nDeletion of an element at a particular position.\n" RESET);
                printf("Enter the size of the array: ");
                scanf("%d", &n);
                printf("Enter the array elements: ");
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &arr[i]);
                }
                printf("Enter the position: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= n)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    item = arr[pos];
                    for (i = pos; i < n - 1; i++)
                    {
                        arr[i] = arr[i + 1];
                    }
                    n = n - 1;
                    printf("Element %d deleted from the position %d.\n", item, pos);
                    printf(BLUE "Array after deletion: " RESET);
                    for (i = 0; i < n; i++)
                    {
                        printf("%5d", arr[i]);
                    }
                }

                break;

            default:
                printf(RED "Invalid choice.\n" RESET);
                break;
            }
        }
        else
        {
            printf(RED "Invalid choice.\n" RESET);
        }
    } while (x != 3);
}

int main()
{
    char choice;
    int n, i;
    loading();

    playSound();

    printf("\n^.^ > WELL 'HELLO' THERE, WELCOME TO THE PROGRAM! < ^.^\n");
    printf("Do you want to know what this program does?\n");
    printf("If this makes you curious, press >> Y\n");
    printf("If not, press >> N\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf(YELLOW "\nThis is a menu-driven program in C.\n" RESET);
        printf("It allows the user to perform various operations on an array,\n");
        printf("such as insertion and deletion at different positions, beginning, or ending.\n");
        yes();
    }
    else if (choice == 'n' || choice == 'N')
    {
        yes();
    }
    else
    {
        printf(RED "Invalid input!\n" RESET);
    }
    return 0;
}
