#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void clear() {
    system("cls");
}
void showBanner() {
    puts("           =:                                                                                :=***=:         ");
    puts("           **                                                                              :*#%#####*-       ");
    puts("           +%.                               .                                            :#%%%=--+###+.     ");
    puts("           +#-              :+             :*#*.                                         .*%%#-    .-+##:    ");
    puts("           +#*              =#:          -*#%%%+                                         +#%#+        :##.   ");
    puts("          .*##              =%-        -##+-*##*                                        .#%%%.       .%%%:   ");
    puts("          .###.             +#=        -:   *#%#.                                       -#%#*       :%@@@%.  ");
    puts("          -###.             +##.            +#%#:                                       -#%#*      =%@@@@=   ");
    puts("          =#%#.            .*##:            =#%%-                                       .####*===+%%@@@@#.   ");
    puts("          +%%#            .:##%-            =%%%=                                        :*####%%##%@@@@=    ");
    puts("         .#%%*      .-=*###%%%%=            -#%#+                           .==+++-.       -+#####**%%%%:    ");
    puts("         -#%#=.:-=*#########%%%+            -#%##                          -#@%%%%##*:             +%%%%     ");
    puts("         +#%%####**+++=--::-#%%*            -#%##                         .#@@%%%%%%%#*:           *%%@#     ");
    puts("        .*%##.             .#%%*            -####                          *@%*. :+%%%##-          #%%@+     ");
    puts("        -###*              :#%%*            -####                         .#%=     .*%%##-        .%%%@-     ");
    puts("        =#%#=              -#%#+            -####                         .###       *%%#*.       -%%%@:     ");
    puts("        *#%#-              =#%#+            -####.                        .*##-      .%###:       =%%%%:     ");
    puts("        ###%:              +#%#=            -###%.                         +###:     +####.       -%%%@:     ");
    puts("       :####.              ##%#-            :###%:                         :##%+    =####-        -%@%@:     ");
    puts("       =#%##               ###%-            :###%:                          +#%%*-:+####-         =%%%%.     ");
    puts("       *#%%=               *###-            :##%%--+=:                       =#%%%%%%##-          +%%%%      ");
    puts("      -##%%.               *#%#=            .##@@%###=.        +##=           :+####*=.           *%%%#      ");
    puts("      *#%%*                ##%%+            .#%@@%#*+:        -%%%%-             ...              *%%%*      ");
    puts("      -=*#:                #%%%+          .-+%%%#+:           .+**=                               #%%%*      ");
    puts("        ..                 =#%*-        .+#*+=:..                                                 #%%%*      ");
    puts("                           :-.                                                                    #%%%*      ");
    puts("                                                                                                  #%%%#      ");
    puts("                                                                                                  *#%#%      ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  -*%%#.     ");
    puts("                                                                                                   -=:.      ");
    printf("\n請按任意鍵繼續...\n");
    getch(); // 等使用者閱讀
    clear();
}


// 倒字母三角形
void print_triangle() {
    char ch;
    while (1) {
        printf("請輸入一個字元（a ~ n）：");
        scanf(" %c", &ch);

        if (ch >= 'a' && ch <= 'n') {
            clear();
            for (char i = ch; i >= 'a'; i--) {
                for (char j = i; j <= ch; j++) {
                    printf("%c", j);
                }
                printf("\n");
            }
            printf("\n按任意鍵返回主選單...");
            getch();
            clear();
            break;
        } else {
            printf("輸入錯誤，請重新輸入 a ~ n 的字元。\n");
        }
    }
}

// 乘法表
void print_table() {
    int n;
    while (1) {
        printf("請輸入一個整數（1 ~ 9）：");
        scanf("%d", &n);

        if (n >= 1 && n <= 9) {
            clear();
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    printf("%2d ", i * j);
                }
                printf("\n");
            }
            printf("\n按任意鍵返回主選單...");
            getch();
            clear();
            break;
        } else {
            printf("輸入錯誤，請重新輸入 1 ~ 9 的整數。\n");
        }
    }
}

// 是否繼續
void ask_continue() {
    char ans;
    while (1) {
        printf("Continue? (y/n)：");
        scanf(" %c", &ans);

        if (ans == 'Y' || ans == 'y') {
            clear();
            break;
        } else if (ans == 'N' || ans == 'n') {
            printf("結束程式，返回作業系統...\n");
            exit(0);
        } else {
            printf("輸入錯誤，請輸入 y 或 n。\n");
        }
    }
}

int main() {
    int pw1, pw2, pw3, pw4;
    int attempts = 0;
    showBanner(); // 顯示開場圖

    // 密碼驗證
    do {
        printf("請輸入四位數字密碼：\n");
        scanf("%d %d %d %d", &pw1, &pw2, &pw3, &pw4);

        if (pw1 == 2 && pw2 == 0 && pw3 == 2 && pw4 == 5) {
            printf("輸入正確\n");
            system("cls");
            break;
        } else {
            attempts++;
            printf("密碼錯誤，請重新輸入（已錯誤 %d 次）\n", attempts);
            if (attempts == 3) {
                printf("ERROR\a\n");
                return 0;
            }
        }
    } while (1);

    // 主選單
    char choice;
    while (1) {
        puts(" --------------------------");
        puts("| A. 字元倒三角形         |");
        puts("| B. 顯示乘法表 (1~9)     |");
        puts("| C. 結束程式 (y/n)       |");
        puts(" --------------------------");
        printf("Please choose an option：\n");  
        scanf(" %c", &choice);
        clear();

        if (choice == 'A' || choice == 'a') {
            print_triangle();
        } else if (choice == 'B' || choice == 'b') {
            print_table();
        } else if (choice == 'C' || choice == 'c') {
            ask_continue();
        } else {
            printf("選項錯誤，請重新輸入。\n");
        }
    }
    system("pause");
    return 0;
}
/*在這次撰寫 C 語言選單功能的過程中，我遇到了幾個實際操作上常見但容易忽略的問題。首先是在 printf() 中誤用了中文字前的跳脫字元 \，例如 \項，這會導致編譯器誤判為非法的 。這讓我意識到在中英文混合輸出時，必須特別注意 \ 只能搭配像 \n、\t 等合法語法使用，否則會造成編譯錯誤。

第二個問題就是 .exe 檔案無法重新編譯，原因是程式尚未完全關閉。這是初學者常遇到的情況，也提醒我在每次執行完程式後，必須確實關閉程式視窗，或透過工作管理員強制關閉，才能正常重新編譯。

這些錯誤雖然不大，但都屬於實務中非常常見的細節，讓我體會到「寫對」和「跑得動」其實是兩件事。透過這次練習，我不只熟悉了基本的條件判斷與 getch()、system("cls") 的使用，也更能掌握錯誤訊息的判讀與除錯技巧，未來在實作複雜功能時會更有信心處理各種突發狀況。*/




 
 
 
 
 
 
 
 
 
 
