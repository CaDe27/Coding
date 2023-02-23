
function [L] = Mi_Cholesky(A)
    n = length(A);
    L = A;
    %lo unico que debemos aniadir al algoritmo es multiplicar cada elemento
    %de la columna i por sqrt(A(i,i)), que como ya tenia division por A(i,i)
    %, en total es como dividir por raiz de A(i,i) y 
    for i = 1:n-1
       L(i+1:n, i+1:n) = L(i+1:n, i+1:n) - (L(i+1:n, i)*L(i, i+1:n))./L(i,i);
       L(i, i+1:n) = zeros(1,n-i);
       L(i,i) = sqrt(L(i,i));
       L(i+1:n, i) = L(i+1:n, i)./L(i,i);
    end
    L(n,n) = sqrt(L(n,n));
end
