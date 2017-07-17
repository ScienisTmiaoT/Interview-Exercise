#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int mainT() {
    int Test, N, S, Tf;
    ifstream in("A-small-attempt0.in");
    if(!in.is_open()) {
        cout << "Error Opening File" << endl;
        return 0;
    }
    ofstream out("A-small-attempt0.out");
    if(!out.is_open()) {
        cout << "Error Opening File" << endl;
        return 0;
    }
    in >> Test;
    int Case = Test;
    while(Test > 0) {
        int sum = 0;
        in >> N >> S >> Tf;
        int city = 0;
        vector<vector<int>> data(N-1, vector<int>(4));
        for(int i = 0; i < N-1; i++)
            in >> data[i][0] >> data[i][1] >> data[i][2];
        bool impos = false;
        bool cflag = false;
        for(int i = N-2; i >= 0; i--) {
            int temp = Tf - data[i][2] - data[i][0];
            data[i][3] = temp / data[i][1] *
                    data[i][1] + data[i][0];
            Tf = data[i][3];
            if(temp < 0) impos = true;
        }
        for(int i = 0 ; i < N-1; i++) {
            if(sum + S <= data[i][3]) {
                city++;
                sum += S;
                cflag = true;
            }
            else
                cflag = false;
            int sumTemp = sum;
            if(sum > data[i][0]) {
                sum = ((sum - data[i][0] - 1) / data[i][1] + 1) *
                      data[i][1] + data[i][0] + data[i][2];
            }
            else
                sum = data[i][0] + data[i][2];
            if(cflag == false && sum - data[i][2] > sumTemp + S) {
                city++;
                cflag = true;
            }
        }
        Test--;
        if(impos)
            out << "Case #" << (Case - Test) << ": IMPOSSIBLE" << endl;
        else
            out << "Case #" << (Case - Test) << ": " << city << endl;
    }
    in.close();
    out.close();
    return 0;
}

int main() {
    int Test, N, S, Tf;
    cin >> Test;
    int Case = Test;
    while(Test > 0) {
        int sum = 0;
        cin >> N >> S >> Tf;
        int city = 0;
        vector<vector<int>> data(N-1, vector<int>(4));
        for(int i = 0; i < N-1; i++)
            cin >> data[i][0] >> data[i][1] >> data[i][2];
        bool impos = false;
        bool cflag = false;
        for(int i = N-2; i >= 0; i--) {
            int temp = Tf - data[i][2] - data[i][0];
            data[i][3] = temp / data[i][1] *
                         data[i][1] + data[i][0];
            Tf = data[i][3];
            if(temp < 0) impos = true;
        }
        for(int i = 0 ; i < N-1; i++) {
            if(sum + S <= data[i][3]) {
                city++;
                sum += S;
                cflag = true;
            }
            else
                cflag = false;
            int sumTemp = sum;
            if(sum > data[i][0]) {
                sum = ((sum - data[i][0] - 1) / data[i][1] + 1) *
                      data[i][1] + data[i][0] + data[i][2];
            }
            else
                sum = data[i][0] + data[i][2];
            if(cflag == false && sum - data[i][2] > sumTemp + S) {
                city++;
                cflag = true;
            }
        }
        Test--;
        if(impos)
            cout << "Case #" << (Case - Test) << ": IMPOSSIBLE" << endl;
        else
            cout << "Case #" << (Case - Test) << ": " << city << endl;
    }
    return 0;
}