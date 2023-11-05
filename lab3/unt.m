a = [0.3 0.2 -0.1 4.2 -2 1.5 0];
b = [0.1 0.2 0.3 4 -2.2 1.6 0.1];

%
figure;

subplot(2, 1, 1); % Создание первого подграфика
plot(a);
title('График a');
xlabel('Индекс элемента');
ylabel('Значение');

subplot(2, 1, 2); % Создание второго подграфика
plot(b);
title('График b');
xlabel('Индекс элемента');
ylabel('Значение');
%

format longG;

ab = Corr1(a, b);
fprintf('%.0f \n',ab)

function p = Corr1(a, b)
    p = sum(a .* b);
end

function p = Corr2(a, b)
    p = sum(a .* b) / (sqrt(sum(a .^ 2)) * sqrt(sum(b .^ 2)));
end
