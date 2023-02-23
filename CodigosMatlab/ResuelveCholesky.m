function [x] = ResuelveCholesky(A, b)
    L = Mi_Cholesky(A);
    y = ResuelveTI(L, b);
    x = ResuelveTS(L', y);
end