n = 4;
A = [3 1 -1 2 6; -5 1 3 -4 -12; 2 0 1 -1 1; 1 -5 3 -3 3]
B = zeros(n, n);
C = zeros(n, n);
y = zeros(1, n);
x = zeros(1, n);

for i = 1:1:n
    B(i, 1) = A(i, 1);
    C(1, i) = A(1, i)/B(1 ,1);
end

for i = 2:1:n
    for j = 2:1:i
        bc = 0;
        for k = 1:1:j-1
            bc = bc + B(i, k)*C(k, j);
        end
        B(i, j) = A(i, j) - bc;
    end
    for j = i+1:1:n
        bc = 0;
        for k = 1:1:i-1
            bc = bc + B(i, k)*C(k, j);
        end
        if(i == 2)
        if(j == 4)
        A(i, j)    
        B(i, k)    
        C(k, j)
        bc            
        end
        end

        C(i, j) = (A(i, j)-bc)/B(i,i);
    end
end

y(1, 1) = A(1, n+1)/B(1, 1);
for i = 2:1:n 
    by = 0;
    for k = 1:1:i-1
       by = by + B(i, k)*y(1, k); 
    end
    y(1, i) = (A(i, n+1)-by)/B(i, i);
end

x(1, n) = y(1 ,n);
for i = n-1:-1:1 
    cx = 0;
    for k = i+1:1:n
       cx = cx + C(i ,k)*x(1, k);
    end
    x(1, i) = y(1, i) - cx;
end
B
C
y
x