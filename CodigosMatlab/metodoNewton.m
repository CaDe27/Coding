function [x,k] = metodoNewton(fname,a, b)
    %{
        IN: 
            fname   - nombre de la función
            a       - inicio del intervalo
            b       - fin del intervalo
        OUT:
            x       - raíz aproximada
            k       - el numero de iteraciones
    %}
    
    %guardo f(a) por si las necesitamos
    % en caso de usar el metodo de la biseccion como
    %paso intermedio
    %f(b) no necesita guardarse, pues solo necesita checarse si esta entre
    %a y x, sino esta entre x y b
    fa = feval(fname, a);
    
    %inicializo mis variables
    %en fx guardo f(x)
    x = (a+b)/2;
    k = 0;
    fx = feval(fname, x);
    tolerancia = 1e-8;
    
    %repetimos el proceso mientras f(x) no este tan cerca de cero como
    %queramos
    while(abs(fx) > tolerancia)
        %calculamos la derivada
        %usamos 1e-5 por el resultado del laboratorio 11
        derivada = dif_centrada(fname, x, 1e-5);
        
        %hacemos la reasignación del método de Newton
        nuevoX = x - fx/derivada;
        
        %checamos si está en el intervalo
        %si sí, continuamos como normalmente
        if( a<= nuevoX && nuevoX <= b)
           x = nuevoX;
        %si no, utilizamos el método de la bisección en esta iteración
        else
            if(fa*fx < 0)
                x = (a+x)/2;
            else
                x = (x+b)/2;
            end
        end
        %ajustamos k y  fx
        k = k+1;
        fx = feval(fname, x);
    end
end