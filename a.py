# int n, k;cin>>n>>k;
#     int x = 1;
#     vector<int> massive(n);
#     repeat(n){
#         cin >> massive[_];
#         x *= massive[_];

#     }
#     string s;
#     cin >> s;
#     int l = 0;
#     int r = n - 1;
#     repeat(s.size()){
#         cout << x % k << " ";
#         if(s[_] == 'L'){
#             x /= massive[l++];
#         } else{
#             x /= massive[r--];
#         }
#     }
for _ in range(int(input())):
    