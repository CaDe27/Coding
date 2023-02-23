function [lambda, v] = potenciaInversa(A, p, q0)
    %{
        Función que utiliza el método de la potencia para regresar el
        eigenpar mas pequeno de la matriz A
    
        IN: 
            A - matriz de la que queremos el eigenpar
            x0 - el vector en el que iniciamos el proceso
                 distinto del vector cero
        OUT:
            lambda - el eigenvalr de A
            v     - un eigenvector asociado al eigenvalor lambda
    %}
    n = length(A);
    k = 60;
    v = q0;
    
    if( det(A - p*eye(n)) == 0)
        lambda = p;
    else 
        for i = 1:k
            v = (A-p*eye(n))\v;
            lambda = norm(v, "inf");
            v = v./lambda;
        end
        
        %para encontrar eigenvalores negativos
        if(sum( (A*v)./v < 0) > 0)
               lambda = -lambda;
        end
        
        lambda = 1/lambda + p;
    end
end