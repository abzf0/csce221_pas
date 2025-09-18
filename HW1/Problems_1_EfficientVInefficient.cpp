 #include <vector>
 #include <iostream>
 using namespace std;

 bool eff12Div(vector<int> vec) {
    int count2 = 0, count3 = 0, count4 = 0;
    for(int num:vec) {
        if(num%4==0) {
            count4++;
        } if(num%3==0) {
            count3++;
        } if(num%2==0) {
            count2++;
        }

        //////////////////

        if(count4 > 0 && count3 > 0) {
            return true;
        } else if(count2 > 1 && count3 > 0) {
            return true;
        }
    } return false;
 }

 bool ineff12Div(vector<int> vec) {
    for(size_t i = 0; i < vec.size()-1; i++) {
        for(size_t j = i+1; j < vec.size(); j++) {
            if((vec[i] * vec[j]) % 12 == 0) {
                return true;
            }
        }
    } return false;
 }