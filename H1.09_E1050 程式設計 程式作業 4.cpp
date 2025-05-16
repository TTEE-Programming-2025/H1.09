#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2025"
#define MAX_ATTEMPTS 3
#define MAX_STUDENTS 10

typedef struct {
    char name[50];
    char id[10];
    int math;
    int physics;
    int english;
    float average;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// 自訂函式：字串相等比較，不使用 strcmp
int myStrEqual(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}

// 個人風格歡迎畫面
void showWelcomeScreen() {
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
    puts("                                                                                                  #%%%*      ");
    puts("                                                                                                  #%%%#      ");
    puts("                                                                                                  *#%#%      ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  +%%#%.     ");
    puts("                                                                                                  -*%%#.     ");
    puts("                                                                                                   -=:.      ");
}

// 功能 1：密碼登入
int login() {
    char input[10];
    int attempt = 0;

    while (attempt < MAX_ATTEMPTS) {
        printf("請輸入 4 位數密碼：");
        scanf("%s", input);
        if (myStrEqual(input, PASSWORD)) {
            printf("登入成功，歡迎使用者！\n");
            return 1;
        } else {
            printf("密碼錯誤，剩餘次數：%d\n", MAX_ATTEMPTS - attempt - 1);
        }
        attempt++;
    }

    printf("錯誤次數過多，系統結束。\n");
    return 0;
}

// 功能 2：主選單
void showMenu() {
    system("cls"); // Windows 用，若是 Linux 請改成 "clear"
    printf("------------[Grade System]----------\n");
    printf("| a. Enter student grades          |\n");
    printf("| b. Display student grades        |\n");
    printf("| c. Search for student grades     |\n");
    printf("| d. Grade ranking                 |\n");
    printf("| e. Exit system                   |\n");
    printf("------------------------------------\n");
}

// 功能 3：輸入學生成績
void enterGrades() {
    printf("請輸入學生人數 (5~10)：");
    scanf("%d", &studentCount);
    if (studentCount < 5 || studentCount > 10) {
        printf("人數錯誤，請重新輸入。\n");
        return;
    }

    for (int i = 0; i < studentCount; i++) {
        printf("\n第 %d 位學生資料：\n", i + 1);
        printf("姓名：");
        scanf("%s", students[i].name);
        printf("學號（6碼）：");
        scanf("%s", students[i].id);
        printf("數學成績：");
        scanf("%d", &students[i].math);
        printf("物理成績：");
        scanf("%d", &students[i].physics);
        printf("英文成績：");
        scanf("%d", &students[i].english);

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
}

// 功能 4：顯示所有成績
void displayGrades() {
    printf("\n%-10s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-10s %-6d %-6d %-6d %-6.1f\n",
               students[i].name, students[i].id, students[i].math,
               students[i].physics, students[i].english, students[i].average);
    }
}

// 功能 5：查詢特定學生
void searchGrades() {
    char searchName[50];
    printf("請輸入要查詢的學生姓名：");
    scanf("%s", searchName);

    for (int i = 0; i < studentCount; i++) {
        if (myStrEqual(students[i].name, searchName)) {
            printf("%s 的成績如下：\n", students[i].name);
            printf("數學：%d  物理：%d  英文：%d  平均：%.1f\n",
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            return;
        }
    }
    printf("查無此學生。\n");
}

// 功能 6：平均成績排序
void gradeRanking() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (students[j].average < students[j + 1].average) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("成績由高至低排序如下：\n");
    displayGrades();
}

// 主程式
int main() {

    if (!login()) return 0;

    char choice;
    while (1) {
        showMenu();
        printf("請選擇功能 (a-e)：");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a': enterGrades(); break;
            case 'b': displayGrades(); break;
            case 'c': searchGrades(); break;
            case 'd': gradeRanking(); break;
            case 'e': {
                char confirm;
                printf("確定要離開嗎？(y/n)：");
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("系統結束，感謝使用！\n");
                    return 0;
                }
                break;
            }
            default: printf("輸入錯誤，請重新選擇。\n"); break;
        }

        printf("按 Enter 鍵繼續...\n");
        getchar(); getchar(); // 等待輸入
    }

    return 0;
}
//討論與心得： 
/*這次我完成了一份簡易成績系統，重點在於練習資料輸入、處理、查詢與排序等基本邏輯，並特別挑戰完全不使用 strcmp() 來比對字串。整個過程讓我更深入理解了 C 語言在「字元陣列」上的底層運作。

我自己寫了一個函式 myStrEqual() 來做字串逐字比對，這讓我學會不能依賴函式庫，要自己處理字元、\0 結尾和每一個字元的比較，這種細節平常用內建函式時很容易忽略。這也讓我更有成就感，因為我真的了解了程式裡是怎麼「知道」兩個字串一不一樣的。

除了字串比較，整個專案還讓我練習了：

struct 用來存學生資料（姓名、學號、成績）

array 來儲存多筆資料

利用迴圈計算平均成績

用氣泡排序把學生按平均分數排序

利用 switch 和 while 建構一個選單系統

我還設計了自己的 ASCII 圖案做為登入畫面，讓整個程式除了功能完整，也多了一點個人特色。

這份程式功能雖然不複雜，但它涵蓋了 C 語言核心的各種基本操作，像是陣列處理、條件判斷、函式使用、資料輸入輸出等。更重要的是，這次我沒有依賴 strcmp()，這讓我對底層邏輯有更紮實的理解，這點比功能本身還有意義。

總結來說，這次專題讓我練到很多 C 語言的基本功，也挑戰了對底層運作的掌握。我會把這個程式留下來，當成日後更進階系統的基礎。 */ 
