 const int inf = 1e9;
#define ctrl(x) (x > 0 ? x : inf)

// минимальный путь от стока к истоку - алгоритм Дейкстры
bool min_way (vector < vector < int > > &D, vector < int > &w, vector < int > &p)
{
    int i, j;
    int n = D.size ();
    vector < int > a(n, 0);
    p.assign (n, 0);
    w.assign (n, inf);
    for (i = 0; i < n; ++ i)
        w[i] = ctrl (D[0][i]);
    a[0] = 1;
    w[0] = 0;
    p[0] = - 1;

    for (i = 0; i < n - 2; ++ i)
    {
        int Min = 2 * inf, iMin = - 1;
        for (j = 0; j < n; ++ j)
            if (!a[j] && w[j] < Min)
            {
                Min = w[j];
                iMin = j;
            }
        
        if (iMin < 0) return;
        a[iMin] = 1;
        
        for (j = 0; j < n; ++ j)        
            if (w[j] > w[iMin] + ctrl(D[iMin][j]))
            {
                w[j] = w[iMin] + D[iMin][j];
                p[j] = iMin;
            }
    }

    return w[n - 1] < inf / 10;
}
// максимальный поток
void max_flow (vector < vector < int > > C, vector < vector < int > > &F)
{
    int i, j;
    int n = C.size ();
    F.assign (n, vector < int > (n, 0));
    vector < vector < int > > Cf = C;    
    vector < int > w, p;
    
    while (min_way (Cf, w, p))
    {
        int s = inf;
        for (i = n - 1; i != 0; i = p[i])
            s = min(s, Cf[p[i]][i]);

        for (i = n - 1; i != 0; i = p[i])
        {
            int u = p[i];
            int v = i;
            F[u][v] += s;
            F[v][u] = - F[u][v];
            Cf[u][v] = C[u][v] - F[u][v];
            Cf[v][u] = C[v][u] - F[v][u];
        }
    }
}
