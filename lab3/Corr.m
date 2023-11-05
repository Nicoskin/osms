f1 = 18;
f2 = f1 + 4;
f3 = f1 * 2 + 1;

time = (0:100-1)/100;

S1 = cos(2*pi* f1 *time);
S2 = cos(2*pi* f2 *time);
S3 = cos(2*pi* f3 *time);

a = 2*S1 + 4*S2 + S3;
b = 1/2 * S1 + 1/3 * S3;

format longG;

S1a = Corr1(S1, a);
S1b = Corr1(S1, b);
S1a2 = Corr2(S1, a);
S1b2 = Corr2(S1, b);
fprintf(' %.0f\n', S1a)
fprintf(' %.0f\n', S1b)
fprintf(' %.2f\n', S1a2)
fprintf(' %.2f\n', S1b2)


function p = Corr1(a, b)
    p = sum(a .* b);
end

function p = Corr2(a, b)
    p = sum(a .* b) / (sqrt(sum(a .^ 2)) * sqrt(sum(b .^ 2)));
end
