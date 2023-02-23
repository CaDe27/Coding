function [Q, R] = miQR(A)
    %{
        IN:
            A - la matriz de m*n la que vamos a obtener la factorización QR
        OUT:
            Q - una matriz ortonormal de m*n
            R - una matriz triangular superior de n*n
            De forma que se cumple A = Q*R
    
    %}
    
    %inicializamos las variables
    [m,n] = size(A);
    Q = A;
    R = zeros(n,n);
    
    %{
        La idea es usar el proceso de normalización de Grahm-Schmidt y
        normalizar en cada paso.
        Q se va a construir como la base ortogonal que devuelve el proceso
        de Gram - Schmidt y R se va a utilizar para normalizar a los 
        vectores de Q (la i-ésima entrada de la diagonal de R tendrá la norma
        del i-ésimo vector columna de Q) y para hacer el cálculo los
        coeficientes que acompañan a las restas en las iteraciones del
        proceso
        
    %}
    
    %normalizamos los n vectores
    for i = 1:n
        
        %asignamos la norma del i-ésimo vector columna de Q a a i-ésima
        %entrada en la diagonal de R
        R(i,i) = norm(Q(1:m, i));
        
        %normalizamos el vector
        Q(1:m, i) = Q(1:m, i)./R(i,i);
        
        %usamos este for para restar este vector a los vectores que faltan
        %es la parte de Gram Schmidt en la que a un vector le restas los
        %anteriores pero hecha en un orden distinto
        for j = i+1:n
            %calculo el producto punto de la j-esima columna y el i-ésimo
            %vector
            R(i,j) = Q(1:m, i)'*Q(1:m, j);
            
            %le resta la parte que corresponde al j-ésimo vector
            Q(1:m, j) = Q(1:m, j) - R(i,j).*Q(1:m, i);
        end
    end
end