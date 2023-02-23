function [x] = ResuelveTS(A, b)
    n = length(A);
    x = zeros(n,1);
    x(n) = b(n)/A(n,n);
    for i = n-1:-1:1
        %primero calculamos el producto punto de los anteriores xi con las
        %entradas correspondientes
        sumas = 0;
        for j = n:-1:(i+1)
            sumas = sumas + A(i,j)*x(j);
        end
        x(i) = (b(i) - sumas)/A(i,i);
    end
end