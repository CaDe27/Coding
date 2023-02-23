function [x] = ResuelveTI(A, b)
    n = length(A);
    x = zeros(n,1);
    x(1) = b(1)/A(1,1);
    for i = 2:n
        %primero calculamos el producto punto de los anteriores xi con las
        %entradas correspondientes
        sumas = 0;
        for j = 1:(i-1)
            sumas = sumas + A(i,j)*x(j);
        end
        x(i) = (b(i) - sumas)/A(i,i);
    end
end
