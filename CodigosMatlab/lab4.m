b = [3;7;-9;5];
A = [16,    -12,    -12,    -16;
    -12,    25,       1,     -4; 
    -12,    1,       17,     14; 
    -16,    -4,      14,     57];
coment = "verificamos que c si sea la fact de choleskyLU (debe mostrar A)"
c = CholeskyLU(A);
c*c'
coment = "verificamos que  resultado del sistema sea el mismo"
coment = "como Resuelve funciona, lo usamos como referencia"
vectorSolucion = Resuelve(A, b)
pruebaCholeskyLU = ResuelveCholeskyLU(A, b)
%6
% Lo unico que cambia es multiplicar por la matriz diagonal D, que
% el efecto total que tiene es multiplicar la i-esima columna de A por la
% raiz de A(i,i)
%todo lo demas es igual
coment = "verificamos que c si sea la fact de cholesky (debe mostrar A)"
C = Mi_Cholesky(A);
C*C'
coment = "verificamos que  resultado del sistema sea el mismo"
coment = "como Resuelve funciona, lo usamos como referencia"
vectorSolucion = Resuelve(A, b)
pruebaCholesky = ResuelveCholesky(A, b)
