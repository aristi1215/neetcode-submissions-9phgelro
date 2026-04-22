#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        if (grid[0][0] != 0)
        {
            return -1;
        }

        vector<vector<bool>> 
        visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;

        int rows = grid.size();
        int cols = grid[0].size();
        int length = 1;
        q.push({0, 0});
        visited[0][0] = true;

        // Recorrer la grid completa
        while (!q.empty())
        {
            // Recorrer cada nivel de la grid. Como en BFS
            int qsize = q.size();
            for (int i = 0; i < qsize; i++)
            {

                //Sacamos la coordenada actual

                pair<int, int> coord = q.front();
                int r = coord.first;
                int c = coord.second;
                q.pop();

                //Si es la casilla final terminamos
                if (r == rows - 1 && c == cols - 1)
                {
                    return length;
                }


                //Crear una forma iterativa de poder acceder a todos los vecinos y no hardcodear cada llamada
                //Esto no representa los verdaderos vecinos, sino el movimiento desde la casilla actual.
                //Es decir, me muevo 1 o -1 hacia los lados o 1 o -1 verticalmente y eso es el movimiento

                vector<pair<int, int>> neighboors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{1,1},{-1,-1},{-1,1},{1,-1}};

                //Iteramos por cada vecino y vemos si esta dentro de los límites de la grid, si es así la añadimos al nivel.
                for (auto &[dr, dc] : neighboors)
                {
                    if (min(r + dr, c + dc) < 0 || r + dr >= rows || c + dc >= cols || grid[r + dr][c + dc] == 1 || visited[r + dr][c + dc])
                    {
                        continue;
                    }
                    q.push({r + dr, c + dc});
                    visited[r + dr][c + dc] = true;
                }
            }

            length++;
        }
        return -1; 
    }


};