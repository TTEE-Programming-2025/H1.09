#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 9
#define PASSWORD 2025

char seats[SIZE][SIZE];

void initializeSeats() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            seats[i][j] = '-';
}

void displaySeats() {
    printf(" \\123456789\n"); 
    for (int i = SIZE - 1; i >= 0; i--) {
        printf("%d", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

void generateReservedSeats() {
    int count = 0;
    while (count < 10) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (seats[row][col] == '-') {
            seats[row][col] = '*';
            count++;
        }
    }
}

void autoArrange(int num) {
    int found = 0;
    for (int i = 0; i < SIZE && !found; i++) {
        for (int j = 0; j <= SIZE - num; j++) {
            int canArrange = 1;
            for (int k = 0; k < num; k++) {
                if (seats[i][j+k] != '-') {
                    canArrange = 0;
                    break;
                }
            }
            if (canArrange) {
                for (int k = 0; k < num; k++) {
                    seats[i][j+k] = '@';
                }
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("No consecutive seats available.\n");
    }
}

void chooseSeats(int n) {
    int row, col;
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Enter seat (column-row): ");
            scanf("%d-%d", &col, &row);
            if (col < 1 || col > 9 || row < 1 || row > 9) {
                printf("Invalid input! Try again.\n");
                continue;
            }
            if (seats[row-1][col-1] != '-') {
                printf("Seat already taken! Try another.\n");
                continue;
            }
            seats[row-1][col-1] = '@';
            break;
        }
    }
}

void confirmReservation() {
    printf("Confirm reservation? (y/n): ");
    char ans;
    scanf(" %c", &ans);
    if (ans == 'y' || ans == 'Y') {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@')
                    seats[i][j] = '*';
    } else {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (seats[i][j] == '@')
                    seats[i][j] == '-';
    }
}

int main() {
    int password, attempt = 0;
    srand(time(0));
    initializeSeats();
    
    // Password check
    while (attempt < 2) {
        printf("Enter 4-digit password: ");
        scanf("%d", &password);
        if (password == PASSWORD) {
            printf("Welcome!\n");
            break;
        } else {
            printf("Incorrect password!\n");
            attempt++;
        }
    }
    if (attempt == 2) {
        printf("Access denied.\n");
        return 0;
    }

    char choice;
    do {
        printf("--------- [Booking System] ---------\n");
        printf("a. Available seats\n");
        printf("b. Arrange for you\n");
        printf("c. Choose by yourself\n");
        printf("d. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                initializeSeats();
                generateReservedSeats();
                displaySeats();
                printf("Press any key to return to menu...\n");
                getchar();
                getchar();
                break;
            case 'b': {
                int num;
                printf("How many seats do you need? (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    autoArrange(num);
                    displaySeats();
                    confirmReservation();
                } else {
                    printf("Invalid number.\n");
                }
                break;
            }
            case 'c': {
                int num;
                printf("How many seats do you want to choose? (1-4): ");
                scanf("%d", &num);
                if (num >= 1 && num <= 4) {
                    chooseSeats(num);
                    displaySeats();
                    confirmReservation();
                } else {
                    printf("Invalid number.\n");
                }
                break;
            }
            case 'd':
                printf("Continue? (y/n): ");
                char cont;
                scanf(" %c", &cont);
                if (cont == 'y' || cont == 'Y') {
                    continue;
                } else if (cont == 'n' || cont == 'N') {
                    printf("Goodbye!\n");
                    return 0;
                } else {
                    printf("Invalid input! Exiting...\n");
                    return 0;
                }
        }
    } while (1);

    return 0;
}

/*
(英文版)Discussion and Reflection:

This project taught me how to combine different C programming skills, such as using loops, conditional statements, functions, and arrays to build a complete seat booking system. 
Implementing the random reservation part helped me understand how to use the rand() function and how to control the random process to avoid repeated seat selection.
Moreover, managing user input validation was an important practice to make the system more stable and user-friendly.
Handling different user cases such as wrong inputs or unavailable seats made me realize the importance of robust input checking in real applications.
Through this assignment, I improved my problem-solving skills, learned how to organize program structure, and also practiced writing meaningful comments to explain my logic clearly.

Overall, this exercise gave me a deeper understanding of practical C programming beyond just syntax.
*/
/*
(中文版)討論與心得：

這個專案讓我學會如何結合不同的 C 語言技巧，例如使用迴圈、條件判斷、函式與陣列，來建構一個完整的座位訂位系統。
在實作隨機訂位的部分，讓我了解如何使用 rand() 函式，以及如何控制隨機過程，避免重複選取同一個座位。
此外，處理使用者輸入驗證也是一個重要的練習，使系統更穩定且更具使用者友善性。
應對錯誤輸入或座位無法使用等不同情境，讓我意識到在實際應用中，強化輸入檢查的重要性。
透過這份作業，我提升了解決問題的能力，學會如何組織程式結構，同時也練習了撰寫有意義的註解，以清楚說明我的程式邏輯。

整體而言，這次練習讓我對 C 語言實作有了更深入的理解，不僅僅停留在語法層面。
*/


