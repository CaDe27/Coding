function [y] = mi_softmax2(x)
    %creamos un arreglo cuyas componentes sean todas el máximo
    % y se lo restamos al orignal para crear el vector z
    maxi = ones(length(x), 1).*max(x);
    y = x - maxi';
    y = mi_softmax(y);
end