#include <iostream>
#include <cstring>
#include "Toni_Stack.cpp"

using namespace std;

int quadratic_mss(const int pInt[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        int thisSum = 0;
        for (int j = i; j < size; j++) {
            thisSum += pInt[j];
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int cubic_mss(const int pInt[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int thisSum = 0;
            for (int k = i; k <= j; k++) {
                thisSum += pInt[k];
            }
            if (thisSum > maxSum) {
                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int linear_mss(const int pInt[], int size) {
    int maxSum = 0;
    int thisSum = 0;
    for (int i = 0; i < size; i++) {
        thisSum += pInt[i];
        if (thisSum > maxSum) {
            maxSum = thisSum;
        } else if (thisSum < 0) {
            thisSum = 0;
        }
    }
    return maxSum;
}

void lab1() {
    static const int defaultTest[] = {1, 2, -30, 4, 5};
    static const int defaultResult = 9;
    static const int defaultSize = sizeof(defaultTest) / sizeof(int);
    int mss1 = cubic_mss(defaultTest, defaultSize);
    int mss2 = quadratic_mss(defaultTest, defaultSize);
    int mss3 = linear_mss(defaultTest, defaultSize);
    cout << "default" << endl << "mss1: " << mss1 << endl << "mss2: " << mss2 << endl << "mss3: " << mss3 << endl
         << "expected: " << defaultResult << endl;

//more test cases here
// A
    static const int aTest[] = {711, 118, 264, 55, -480, 347, -671, -340, 957, 526, 685, -602, -998, -558, 60, -420,
                                -517, 934, -185, 877, 463, 708, -832, -172, 177, -119, -574, 286, -816, 178, -236, -590,
                                -302, 426, -348, 684, -238, 139, 185, 174, -827, -813, -254, -316, 385, 195, 518, -999,
                                233, -70, 352, 438, 217, -97, -299, -468, -742, 394, 502, -140, 772, -333, 815, -38,
                                825, -449, 533, -610, -258, -393, -903, 635, 447, -603, 405, 707, 190, 551, -965, -759,
                                455, -650, -612, 841, 797, 467, 419, -862, 472, -815, -455, 377, -974, 160, -869, -992,
                                -645, -23, 452, -198};
    static const int aSize = sizeof(aTest) / sizeof(int);
    mss1 = cubic_mss(aTest, aSize);
    mss2 = quadratic_mss(aTest, aSize);
    mss3 = linear_mss(aTest, aSize);
    cout << "A" << endl << "mss1: " << mss1 << endl << "mss2: " << mss2 << endl << "mss3: " << mss3 << endl << endl;
// B
    static const int bTest[] = {696, 676, 127, 70, 759, 704, 916, 404, 682, 864, 895, 691, 235, 228, -96, 17, 469, 123,
                                98, -45, 619, 579, 170, 23, 871, 999, 508, -16, 81, -89, 880, 944, -75, 589, 444, 559,
                                -94, 477, 750, 360, 574, 51, 875, 218, -72, 176, 722, 167, -47, 458, -58, -25, 248, 474,
                                281, 716, 310, 672, 306, 813, 992, 180, 128, 189, 982, -24, 610, 483, 228, 544, 313,
                                230, 192, 618, 15, 644, 570, 753, -11, 684, 746, 103, 144, 103, 915, -38, 372, 268, 19,
                                701, 65, 971, 417, 607, 738, -4, 700, 343, 883, 627, -28, 920, 494, 614, 323, 480, 387,
                                414, 642, 64, 879, 825, 395, 657, 405, 946, 508, 194, 525, -84, 359, 895, 672, 980, 16,
                                437, 773, 491, 515, 921, 372, -33, 616, 656, -38, 31, 670, 466, 221, 841, 181, 716, 905,
                                462, 377, 212, 366, 673, 711, 1, 926, 649, 472, 822, 380, 289, 128, 563, -79, 289, 301,
                                348, 385, 200, 549, 785, 885, 340, 559, 738, 460, 208, 269, 937, 484, 779, 675, 522, 97,
                                188, 335, -61, 683, 432, 269, 157, 344, -94, 916, 647, 553, 946, 378, 604, 553, -2, -50,
                                630, 741, 111, 412, 127, 761, 391, 646, 788, -89, 852, 956, 856, 26, 778, 839, 578, 431,
                                692, 597, 296, 469, 141, 873, -69, 217, 806, 616, 896, -58, 776, 122, 424, 220, 862,
                                135, -82, 330, 148, 772, 820, 35, 995, 997, 887, 927, 8, 857, 843, 309, 230, 579, 362,
                                957, 509, 390, 336, -17, -24, 723, 301, -49, 945, 271, 841, 458, -62, 317, 258, 927,
                                980, -33, 105, 343, 691, 16, 420, 32, 890, 946, 659, 901, -83, 897, 805, 889, 441, -89,
                                794, 928, 722, 861, 204, 147, 881, -14, 902, 565, 483, 677, 530, 643, -37, 502, 621,
                                -36, 5, 215, 361, 945, 537, 50, -63, 988, 489, 406, 826, 99, 530, 139, 901, 377, 960,
                                765, 167, 635, 83, 386, 10, 143, 275, 574, 168, 367, 529, 158, 965, 230, 804, 421, 281,
                                59, 824, 92, 280, 54, 278, 16, 407, 31, 413, -70, 876, 263, 520, 220, 436, 146, -70,
                                921, 626, 856, 252, 889, 140, 600, 823, 410, 992, 265, 453, 588, 638, 675, 723, 463,
                                701, 496, 120, -82, 660, -46, 655, 529, -75, 203, 115, 968, 994, 393, 274, 190, 377,
                                -23, 716, 360, 913, 111, 356, -24, 616, 397, 173, 263, 40, -16, -17, 217, 909, 174, 845,
                                643, 628, -75, 758, 179, 346, 66, 373, 662, 60, 638, 705, 714, 531, 149, 823, 720, 720,
                                337, 268, 385, 812, 743, 693, 28, 48, 525, 336, 461, 431, 404, 422, 671, 934, 63, 245,
                                154, 823, 357, 309, 11, 265, 16, 251, -25, 347, 397, 322, 609, 455, 679, -33, 719, -81,
                                585, 61, 820, 701, 801, 779, 332, 595, -5, 844, 762, 349, 119, 683, 766, 16, 245, 284,
                                104, 378, 287, 246, 578, 547, 959, 443, 100, 588, 129, 463, 267, 344, 531, 317, -72,
                                844, 626, -58, 848, 859, 692, 525, 371, 110, 210, 454, 171, 761, 732, 182, 561, -6, 60,
                                942, 757, 818, 285, 295, 13, 21, 403, 953, 125, 417, 650, 80, 29, 777, 478, 806, 682,
                                823, 986, 347, 988, 313, 866, 27, 589, 818, 365, 800, 184, 871, 103, 122, 844, 246, 25,
                                611, 898, 5, 79, 808, 796, 329, 704, 547, -7, 870, 273, 443, 173, 656, 691, 570, 13, 91,
                                775, 872, 554, 500, 745, 987, -16, 598, 445, 63, 343, 232, 430, 211, 429, 855, 683, 455,
                                89, 928, 602, 87, 505, 98, 872, -20, 92, 447, 630, 935, 85, 815, 585, 573, 763, 948,
                                -70, 405, 358, 743, 221, 70, 206, 114, 455, 331, 93, 823, 239, 626, 749, 430, 319, 389,
                                666, 938, 57, -62, 571, 698, 307, 582, 499, 597, 847, 313, 288, 374, 151, 745, 335, 907,
                                53, 76, 455, 228, 433, 32, 846, 823, 529, 64, 461, 133, 144, 929, 209, 801, -17, 754,
                                186, 514, 54, 636, 551, -18, 302, 661, 334, 100, 386, 920, 578, 705, 617, 772, 775, 613,
                                276, 817, 806, 412, 151, 209, 522, -10, 539, 506, 722, 927, 832, 833, 10, 826, 783, 844,
                                57, -5, 498, 563, 103, 125, 542, 624, 682, 905, 750, 754, 1000, 334, 866, 681, 717, 826,
                                584, -58, 107, 37, 235, 346, 907, -43, 161, 972, 622, 272, 960, 919, 333, 893, 492, 607,
                                398, -43, 705, 972, 553, -75, 517, 410, 815, 722, 470, 876, -9, 725, 156, 856, 711, 418,
                                340, 198, 257, 581, 168, 128, 32, 520, 498, 874, 482, 864, 878, 69, 132, 606, -97, 80,
                                688, -3, 542, 691, 312, 478, 467, 121, 731, 459, 589, 864, 701, 661, 984, 879, 723, 8,
                                529, 487, 682, 385, 366, 349, 511, 204, 354, 498, 433, 700, 327, 259, 823, 162, 119, 85,
                                418, 506, -1, 78, 34, -24, 557, 630, 225, 96, 870, 881, 711, 349, 527, 626, 93, 17, 633,
                                681, -55, 764, -88, 842, -4, 106, 661, 68, 136, 648, 434, 976, 332, 808, 721, 63, 201,
                                856, 993, 742, 937, 845, 630, 643, 751, 119, 107, 362, 805, 44, 211, 415, 32, 498, 408,
                                522, -83, 352, 918, 929, 928, 676, 499, 178, 831, -14, 323, 596, 43, 631, -78, 433, 631,
                                181, 20, 456, 106, -23, 52, 964, 71, 198, 109, 879, 937, 681, 857, 806, 793, 669, 76,
                                774, 554, 524, -23, 486, 389, 971, -88, 677, 788, -75, 573, 56, 193, 736, 542, 665, 48,
                                264, 105, 769, 305, 807, 195, 559, 976, 510, 735, 757, 532, 413, 102, 960, 165, 291,
                                388, 114, 884, 824, 236, 400, 733, 683, -45, 833, 348, 330, 212, 422, -14, -84, 216,
                                400, 667, 690, 446, 928, 83, 32, 701, 821, 608, 580, -45, 22, 902, 432, 864, -27, 164,
                                -52, -62, 863, 848, 792, 270, 158, 344, 278, 349, 548, 441, 183, -90, 373, 615, 956,
                                447, 55, 349, 368, 516, 984, 312, 204, 47, -44, 621, 398, 1, 978, 397, -61, 109, 32};
    static const int bSize = sizeof(bTest) / sizeof(int);
    mss1 = cubic_mss(bTest, bSize);
    mss2 = quadratic_mss(bTest, bSize);
    mss3 = linear_mss(bTest, bSize);
    cout << "B" << endl << "mss1: " << mss1 << endl << "mss2: " << mss2 << endl << "mss3: " << mss3 << endl << endl;
// C
    static const int cTest[] = {-342, -628, -952, -537, -989, -584, -671, -59, -207, -798, -885, -476, -187, -380, -30,
                                -210, -810, -940, -790, -494, -503, -387, -139, -259, -617, -389, -438, -709, -46, -257,
                                -403, -844, -837, -95, -588, -71, -579, -781, -320, -106, -664, -629, -797, -212, -773,
                                -74, -211, -380, -189, -960, -421, -333, -391, -152, -141, -907, -792, -650, -243, -615,
                                -422, -253, -565, -773, -764, -575, -366, -93, -649, -195, -991, -807, -799, -872, -798,
                                -635, -517, -614, -599, -223, -136, -915, -847, -641, -775, -93, -262, -301, -296, -513,
                                -307, -488, -34, -278, -890, -618, -975, -102, -883, -409};
    static const int cSize = sizeof(cTest) / sizeof(int);
    mss1 = cubic_mss(cTest, cSize);
    mss2 = quadratic_mss(cTest, cSize);
    mss3 = linear_mss(cTest, cSize);
    cout << "C" << endl << "mss1: " << mss1 << endl << "mss2: " << mss2 << endl << "mss3: " << mss3 << endl << endl;
// D
    static const int dTest[] = {961, 628, 74, 865, 532, 947, 291, 264, 739, 113, 228, 739, 192, 591, 104, 836, 102, 529,
                                87, 370, 875, 102, 300, 398, 838, 573, 717, 165, 816, 192, 893, 280, 277, 879, 7, 465,
                                97, 277, 95, 979, 791, 418, 759, 374, 203, 209, 418, 534, 499, 888, 726, 372, 279, 176,
                                766, 889, 548, 587, 755, 58, 525, 282, 975, 747, 88, 923, 297, 120, 423, 67, 62, 362,
                                469, 672, 219, 756, 340, 664, 223, 901, 475, 214, 631, 629, 763, 499, 207, 629, 626,
                                354, 850, 387, 528, 188, 395, 50, 299, 7, 303, 353};
    static const int dSize = sizeof(dTest) / sizeof(int);
    mss1 = cubic_mss(dTest, dSize);
    mss2 = quadratic_mss(dTest, dSize);
    mss3 = linear_mss(dTest, dSize);
    cout << "D" << endl << "mss1: " << mss1 << endl << "mss2: " << mss2 << endl << "mss3: " << mss3 << endl << endl;

}

// print an array with length n to standard output
void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int a[], int n) {
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        //find min
        int indexOfSmalest = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[indexOfSmalest]) {
                indexOfSmalest = j;
            }
        }
        int tmp = a[i];
        a[i] = a[indexOfSmalest];
        a[indexOfSmalest] = tmp;
    }
}

void insertion_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j > 0 and a[j - 1] > a[j]) {
            int tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
            j -= 1;
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    //create left Array
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    //create right Array
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; //index of first subarray
    j = 0; //index of second subarray
    k = l; //index of merged subarray
    while (i < n1 && j < n2) {
        //go through the 2 arrays and pick the smallest and add it to the resulting Array
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //first has Elements left
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //second has Elements left
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int *merge_sort(int a[], int left, int right) {
    if (right > left) {
        int splitAt = (left + right) / 2;
        merge_sort(a, left, splitAt);
        merge_sort(a, splitAt + 1, right);
        merge(a, left, splitAt, right);
    }
}

bool parenthesesMatcher(char inputString[], int size) {
    Toni_Stack tstack;
    for (int i = 0; i < size; i++) {
        char c = inputString[i];
        if (c == '(') {
            tstack.push(c);
        } else if (c == ')') {
            if (tstack.size() == 0) {
                return false;
            }
            tstack.pop();
        } else {

        }
    }
    if (tstack.size() == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Toni_Stack st;
    std::cout << st.size() << std::endl;
    st.push('a');
    std::cout << st.size() << std::endl;
    st.push('b');
    std::cout << st.size() << std::endl;
    st.push('c');
    std::cout << st.size() << std::endl;
    std::cout << "Pop " << st.pop() << " Size: " << st.size() << std::endl;
    std::cout << "Pop " << st.pop() << " Size: " << st.size() << std::endl;
    std::cout << "Pop " << st.pop() << " Size: " << st.size() << std::endl;

    std::cout << parenthesesMatcher(new char[4]{'(','(',')',')'},4) << std::endl;
    std::cout << parenthesesMatcher(new char[5]{'(','(','(',')',')'},5) << std::endl;
    std::cout << parenthesesMatcher(new char[5]{')','(','(',')',')'},5) << std::endl;
    std::cout << parenthesesMatcher(new char[4]{')','(',')',')'},4) << std::endl;
    std::cout << parenthesesMatcher(new char[8]{'(','(','(',')',')','(',')',')'},8) << std::endl;
    return 0;
}