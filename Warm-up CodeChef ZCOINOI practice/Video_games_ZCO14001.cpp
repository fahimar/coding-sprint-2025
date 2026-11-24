#include<bits/stdc++.h>
using namespace std;

int main()
{
    int widthBox, heightBox;

    cin >> widthBox >> heightBox;

    vector<int> box(widthBox);

    for(int i=0;i<widthBox;i++)
    {
        cin >> box[i];
    }

    int hookLocation = 0;
    int holding = 0;
    int input;

    while(cin >> input) {
        switch (input)
        {
        case 1:
            if (hookLocation > 0) {
                hookLocation--;
            }
            break;
        case 2:
            if (hookLocation < widthBox - 1) {
                hookLocation++;
            }
            break;
        case 3:
            // Command 3 = Pick up (বক্স তোলা)
            // Crane বর্তমানে যে stack-এর উপরে আছে (hookLocation), সেখান থেকে সবচেয়ে উপরের বক্সটা তোলে।
            // শর্ত ১: holding == 0 → crane-এর হাত খালি থাকতে হবে (একসাথে একটার বেশি বক্স ধরা যায় না)।
            // শর্ত ২: box[hookLocation] > 0 → stack-এ অন্তত একটা বক্স থাকতে হবে (খালি stack থেকে তোলা যায় না)।
            // দুটো শর্ত মিললে: crane এখন বক্স ধরে আছে (holding = 1), আর ওই stack-এর height ১ কমে যায়।
            // শর্ত না মিললে command টা ignore হয় (কিছুই বদলায় না)।
            if (holding == 0 && box[hookLocation] > 0) {
                holding = 1;
                box[hookLocation]--;
            }
            break;
        case 4:
            // Command 4 = Drop (বক্স নামানো)
            // Crane যে বক্সটা ধরে আছে, সেটা বর্তমান stack-এর (hookLocation) উপরে রাখে।
            // শর্ত ১: holding == 1 → crane-এর হাতে আসলেই একটা বক্স থাকতে হবে (খালি হাতে drop করার কিছু নেই)।
            // শর্ত ২: box[hookLocation] < heightBox → stack টা already maximum height H-এ পৌঁছে গেলে আর রাখা যাবে না।
            // দুটো শর্ত মিললে: crane-এর হাত খালি হয় (holding = 0), আর ওই stack-এর height ১ বাড়ে।
            // শর্ত না মিললে command টা ignore হয় — crane বক্সটা ধরেই থাকে।
            if (holding == 1 && box[hookLocation] < heightBox) {
                holding = 0;
                box[hookLocation]++;
            }
            break;

        case 0:
            goto print_result;

        default:
            break;
        }
    }

print_result:
    for(int i=0;i<widthBox;i++)
    {
        cout << box[i] << " ";
    }
    cout << endl;
}