// #include<bits/stdc++.h>

// using namespace std;

//PAIRS
// void explainPair(){
    // pair<int,int> p = {1,3};
    // cout<<p.first<<" "<<p.second;

    // pair<int,pair<int,int>> p={3,{34,77}};
    // cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;
//      pair<int,int> arr[] = {{1,3}, {4,6}, {5,1}};
//      cout<<arr[2].second;
// }
// int main(){
//     explainPair();
//     return 0;
// }


//VECTORS
// #include<bits/stdc++.h>

// using namespace std;
//  void explainVector(){
//      vector<int> v; //==> CREATES AN EMPTY CONTRAINER
//       v.push_back(1); //==>ADDS 1 INTO IT
//       v.emplace_back(2); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(7); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(94); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(16); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(0); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(26); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(55); //==>DYNAMICALLY INSERTS 2 AT THE BACK
//       v.emplace_back(37); //==>DYNAMICALLY INSERTS 2 AT THE BACK

//     vector<pair<int,int>> vec;
//     vec.push_back({1,3});
//     vec.emplace_back(5,3); //HERRE WE DON'T NEED CURLY BRACKETS

//     //vector<int> v(5,100); //CONTAINER WITH 5 INSTANCES OF 100 ==> {100,100,100,100,100}
//     // vector<int> v(5); //5 INSTANCES OF ANY GARBAGE VALUE
//     vector<int> v1(5,20);
//     vector<int> v2(v1); //ANOTHER CONTAINER ;COPY OF VECTOR V1

// //ACCESSING VECTOR
//     // cout<<v[4]<<" "<<v.at(0)<<endl;

//     //OR
//     vector<int>::iterator it = v.begin(); //V.BEGIN() RETURNS ADDRESS AND NOT VALUE
//     //vector<int>::iterator it = v.end(); //V.end() RETURNS ADDRESS right after last element
//     //vector<int>::iterator it = v.rend(); //V.BEGIN() RETURNS ADDRESS AND NOT VALUE
//     //vector<int>::iterator it = v.rbegin(); //V.BEGIN() RETURNS ADDRESS AND NOT VALUE
//     // it++;
//     // cout<< *(it)<<"  "<<*(it)<<endl;
//     // it+=2;
//     // cout<< *(it)<<"  "<<*(it);
//     // cout<<v.back()<<" ";

// //PRINTING THE ENTIRE VECTOR
//     // for(vector<int>::iterator it = v.begin();it < v.end();it++){
//     //     cout<< *(it)<<endl;
//     // }
    
    
// //AUTO    
// //PRINTING THE ENTIRE VECTOR
//     // for(auto it = v.begin();it < v.end();it++){
//     //          cout<< *(it)<<" "<<*(it)<<endl;
//     // }
//     // for(auto it:v){
//     //     cout<<it<<" ";
//     // }

// //DELETION 
//     //{1 2 7 94 16 0 26 55 37}
//     // v.erase(v.begin()+2); //deletes 7
//     // for(auto it:v){
//     //     cout<<it<<" ";
//     // } // ==> {1 2 94 16 0 26 55 37 }

//     //{1 2 7 94 16 0 26 55 37}
//     v.erase(v.begin()+2,v.begin()+5); //deletes 7,9,94 and 16 (doesnot include end)
//      for(auto it:v){
//          cout<<it<<" ";
//      } // ==> {1 2 0 26 55 37}
// }


//  int main(){
//     explainVector();
//     return 0;
//  }





//LISTS
// #include<bits/stdc++.h>

// using namespace std;

//  void explainLists(){
//     list<int> ls;
//     ls.push_back(2);  //{2}
//     ls.emplace_back(6);  //{2,6}

//     ls.push_front(9); //{9,2,6}
//     ls.emplace_front(); //{2,6}
//  }

//  void explainStack(){
//     stack<int> st;
//     st.push(2);
//     st.push(6);
//     st.push(3);
//     st.push(9);
//     st.push(0);
//     st.emplace(1);//{1,0,9,3,6,2}
//     cout<<st.top(); //prints 10
// }

// void explainSets(){
//    set<int> st;
//    st.insert(3);
//    st.insert(3);
//    st.insert(3);
//    st.emplace(7);
//    st.insert(0);
//    st.insert(54);
//    st.emplace(9);

   // for(auto itr:st){
   //    cout<<itr<<" ";
   // }  //{0 3 7 9 54}
   // cout<<endl;
   // auto it =st.find(7); //returns iterator with refernce of element 7
   // cout<<*it<<endl;

   //auto it =st.find(1); //whwn element not in set thrn it returns iterator which points right after end()

   // st.erase(3); //deletes  every instrances of 3 and maintains sorted order starting  //{0 7 9 54}
   // for(auto itr:st){
   //    cout<<itr<<" ";
   // }  // ==>{0  7 9 54}

   // int cnt =st.count(0); //returns 1 if the element exists otherwise 0
   // cout<<cnt;

//    for(auto itr:st){
//        cout<<itr<<" ";
//     }  //{0 3 7 9 54}
//     cout<<endl;
//    auto it1= st.find(7);
//    auto it2= st.find(54);
//    //{0 3 7 9 54}
//    st.erase(it1,it2); //returns==>{0 3 54}
//    for(auto itr:st){
//       cout<<itr<<" ";
//    }  //{0 3 7 9 54}

// }

// void explainMap(){
//    map <int ,int> mpp;
//    //map<int,pair<int,int>>mpp;
//    //map<pair<int,int>,int>mpp;

//    mpp[1]=2;//1 is key with value 2
//    mpp.emplace(3,1);
//    mpp.insert({2,4});
//    //mpp[{2,3}]=10;  //pairkey and 10 value ==>{{2,3},10}

   // for(auto it:mpp){
   //    cout<< it.first<<" "<<it.second<<endl;
   // }
   // cout<<mpp[1]<<endl;
//    cout<<mpp[8]<<endl;// ==>returns 0 as there is no 8 as key
//    auto it = mpp.find(1);
//    cout<< it->second;
// } 

//void explainMultiMap(){
   //everything same as map, only it can store multiple keys
   //only mpp[key] cannot be used here
//}

// void explainUnorderedMap(){
//    //same as set and unordered_Set diffeerence
// }
// int main(){
   // explainLists();
   // explainSets();
   // explainMap();
   // explainMultiMap();
   // explainUnorderdMap();
//    return 0;
//  }






//STLAlgorithms
// #include<bits/stdc++.h>

// using namespace std;

// bool comp(pair<int,int> p1,pair<int,int>p2){
//    if(p1.second < p2.second) return true; 
//    if(p1.second > p2.second) return false;
   
//    //WHEN THEY ARE SAME
//    if(p1.first > p2.first) return true;
//    return false;
// }

// void explainSort(){
//     // ASSUMING THERE IS AN ARRAY WITH 4 ELEMENTS
//     // sort(a,a+4); //A POINTS TO START OF ARRAY AND A+4 TO THE END
//     // sort(v.begin(),v>end());//FOR VECTORS

//     // sort(a+2,a+4);//SORT(STARTING ,EXCLUDING END POSITION)

//     // sort(a,a+n, greater<int>);//DESCENDING ORDER

//     pair<int,int> a[]= {{1,2} , {2,1},{4,1}};
//     //SORT ACCORDING TO SECOND ELEMENT
//     //IF SECOND ELEMENT IS SAME THEN SORT  ACCORDING TO FIRST ELEMENT BUT IN DESCENDING
//     sort(a,a+2,comp);//{4,1} ,{2,1},{1,2}
//     //comp is self written comparator of boolean type

//     for(int i=0;i<3;i++){
//         cout<<"{"<<a[i].first<<","<<a[i].second<<"}\n";
//     }
//     void builtinpPopcount(){
//         int nnum=7;
//         int cnt = _builtin_popcount();

//         long long num2 = 1234566666543;
//         int cnt2 = _builtin_popcount();
//     }
//     void permutationOfString(){ //for sorted string
//         string s ="123";
//         do{
//             cout<<s<<endl;
//         }while(nex_permutataion(s.begin(),s>end()))
//     }

// }
// int main(){
//     explainSort();
//     builtinPopcount();
//     permutationOfString();
//     return 0;
// }





//ARRAYS
// #include<iostream>
// #include<bits/stdc++.h> //FOR VECTOR

// using namespace std;

// int main(){


    // REVERSING ARRAY
    // int n;
    // cout<<"Enter number :- ";
    // cin>>n;
    // int arr[100];
    // cout<<"Enter elements of array : ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // cout<<endl;
    // cout<<"Original array : ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // int i=0,j=n-1;
    // while(i<=j){
        // int temp =arr[i];
        // arr[i]=arr[j];
        // arr[j]=temp;
        //OR
    //     swap(arr[i],arr[j]);
    //     i++;
    //     j--;
    // }
    // cout<<"Reversed array : ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    // swap alternate
    // int n;
    // cout << "Enter number : ";
    // cin>>n;
    // int arr[10];
    // cout<<"Enter elements of array : ";
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // cout<<endl;
    // cout<<"Original array : ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;
    // int i=0;
    // while(i+1<n){
    //     swap(arr[i],arr[i+1]);
    //     i = i+2;
    // }
    // cout<<"Alternate swapped array : ";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }

    //Find intersection of two arrays in non decreasing oreder
    // int i=0,j=0;
    // vector<int> ans;
    // while(i<n && j<m){
    //     if(arr1[i]==arr2[j]){
    //         ans.push_back(arr[i]);
    //         i++;
    //         j++;
    //     }
    //     else if(arr1[i]<arr2[j]){
    //         i++;
    //     }
    //     else{
    //         j++;
    //     }
    // }
    
    //PAIR SUM : FIND PAIR IN ARRAY SUCH THAT THEIR SUM IS EQUAL TO THE S
//     return 0;
// }