function[mat] = matrizBaseNewton(x)
    n = length(x);
    mat = zeros(n);
    mat(1:n, 1) = ones(n,1);
    for j = 2:n
    for i = j:n
        mat(i,j) = mat(i,j-1) * (x(i,1)-x(j-1,1));
    end
    end
end

    