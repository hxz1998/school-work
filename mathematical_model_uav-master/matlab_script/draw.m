%% 无人机灯光秀数学建模无人机绘图
% 作者：胡小忠
% 日期：2019年4月5日

%% 初始化工作空间
clear;close all;clc;

%%  绘制摩天轮原有布局
figure(1);
D = 54;d = 5;
R = D / 2;r = 5 / 2;
theta = linspace(0, 2 * pi, 168);
x = R * cos(theta);
y = R * sin(theta);
plot(x + R, y + R, 'om');
hold on;
theta = linspace(0, 2 * pi, 17);
x = r * cos(theta);
y = r * sin(theta);
plot(x + R, y + R, '*b');
x = linspace(-19, 19, 54);
plot(x + R, x + R, '.r');
plot(x + R, -x + R, '.r');
x = linspace(-27, 27, 54);
plot(0 + R, x + R, '.r');
plot(x + R, 0 + R, '.r');
axis([-5, 60, -5, 60])
%% 绘制功夫熊猫原有布局
figure(2);
data = xlsread('./data.xlsx');
[height, width] = size(data);
x = zeros(1, []);
y = zeros(1, []);
x_i = 1;
y_i = 1;
for j = 1:height
    for i = 1:width
        if data(height - j + 1, i) == 1
            x(x_i) = i;
            y(y_i) = j;
            x_i = x_i + 1;
            y_i = y_i + 1;
        end
    end
end
plot(x, y, '.r');

%% 绘制CUMT原有布局
figure(3);
theta = linspace(pi/2, 3/2 * pi, 69);
x = 22 + 22 * cos(theta);
y = 22 + 22 * sin(theta);
plot(x, y, '.b');
hold on;
grid on;
theta = linspace(pi, 2 * pi, 24);
x = 43 + 11 * cos(theta);
y = 11 + 11 * sin(theta);
plot(x, y, '.r');
plot(32, linspace(11, 44, 33), '.m');
plot(54, linspace(11, 44, 33), '.m');
plot(64, linspace(0, 43, 44), '.g');
plot(114, linspace(0, 43, 44), '.g');
x = linspace(64, 88.5, 50);
y = -1.76 * x + 157;
plot(x, y, '.b');
x = linspace(89, 114, 50);
y = 1.76 * x + -156;
plot(x, y, '.b');
plot(134, linspace(0, 44, 44), '.r');
plot(linspace(123, 145, 11), 44, '.m');

get(gcf)
