function[L, U]= mi_LU(A)
    %aqui deberia verificar que si tiene LU
    n = length(A);
    L = eye(n);
    U = A;
    for i = 1:n-1
        %le asignamos a L la i-esima columna
        L(i+1:n, i) = U(i+1:n, i)./U(i,i);
        %actualizamos en U la matriz de i+1 * i+1
        U(i+1:n, i+1:n) = U(i+1:n, i+1:n) - (U(i+1:n, i)*U(i, i+1:n))./U(i,i);
        %asiganmos la i-esima columna a U de ceros
        U(i+1:n, i) = zeros(n-i,1);
    end
end
