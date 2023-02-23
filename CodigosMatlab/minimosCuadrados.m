function [b,m] = minimosCuadrados(x,y)
    %{
        Entrada:
            x:   vector con las coordenadas en x de los puntos
            y:   vector con las coordenadas en y de los puntos
        
        Salida:
            m y b que representan la recta de la forma y = mx + b 
            que aproxima el método de mínimos cuadrados
            
            m: pendiente de la recta
            b: distancia del punto en x = 0 al origen
    %}
    
    %{
      con la parte siguiente nos aseguramos de que usar los vectores iniciales 
      (x, y) como vectores columna
     
      si solo hay una fila, entonces lo transponemos
    %}
    [n, ~] = size(y);
    if n == 1
        y = y';
    end
    
    [n, m] = size(x);
    if n == 1
         x = x';
         %aprovechamos para reasignar el numero de filas de x que vamos a
         %utilizar en lo que resta del codigo
         n = m;
    end
    
    %asignamos a la matriz A que utiliza el método
    A = ones(n, 2);
    A(:, 2)   = x;
    
    %hacemos la factorización QR de A (A = QR)
    % con Q matriz ortonormal y R triangular superior
    [Q, R] = miQR(A);
    
    % ya sólo tenemos que resolver el sistema
    % R*[b;m] = Q'*y
    %para ver como se deduce esta fórmula revise los anexos del documento
    %presentado
    aux = ResuelveTS(R, Q'*y);
    b = aux(1);
    m = aux(2);
    
end