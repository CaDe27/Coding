function [y] = mi_softmax(x)
    %funcion que proyecta un vector x
    %	sobre el intervalo [0, 1]
	
    %	en la componente i:
    % 	xi = exp(xi) / suma [1:n] de exp(xj) (iterando sobre j)
   
    %IN
    %    x.- vector con n entradas

    %OUT
    % 	y.- el vector proyectado
    
    %calculamos la exponencial de cada componente y suma para aplicarla al final 
    %al vector

    suma = 0;
    y = zeros(length(x), 1);
    for i=1:length(x)
        y(i) = exp(x(i));
        suma = suma + y(i);
    end 
    y = y ./ suma;
end