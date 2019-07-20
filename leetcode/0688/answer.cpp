class Solution {

public:   

    double knightProbability(int N, int K, int r, int c) {

        int **dp0 = new int*[N];

        for (int i = 0; i < N; i++) dp0[i] = new int[N];

        int moves[8][2] = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

        for (int i = 0; i < N; i++)

            for (int j = 0; j < N; j++)

                dp0[i][j] = 1;

        dp0[r][c] = 1;

        int x = 0;

        for (int k = 0; k < K; k++) {

            int **dp1 = new int*[N];

            for (int i = 0; i < N; i++) dp1[i] = new int[N];  

            for (int i = 0; i < N; i++) {

                for (int j = 0; j < N; j++) {

                    dp1[i][j] = 0;

                    for (int m = 0; m < 8; m++) {

                        int row = i + moves[m][0];

                        int col = j + moves[m][1];

                        if (row < N && col < N && row >= 0 && col >= 0)

                            dp1[i][j] += dp0[row][col]; 

                    }

                }

            }

            dp0 = dp1;

        }

        return (double) dp0[r][c] / pow(8, K); 

    }

};
