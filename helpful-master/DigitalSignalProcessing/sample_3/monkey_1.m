% ʹ��hamming�����������
% Ҫ��Rs = 50, ͨ�����Ϊw = wp - ws = 0.628
% hamming����N=40ʱ�ŷ���Ҫ��
clear;
clc;
wp = 0.3*pi;
ws = 0.5*pi;
rp = 0.25;
rs = 50;

% ��һ�ʵڶ���
% N ȡ15��45
% N = 45;
N = 15;
wc = (wp+ws)/2;
n = [0:1:N - 1];
hd = ideal_lp(wc, N);
if N == 15
    w_result = (hanning(N))';
    h = hd .* w_result;
    [db, mag, pha, grd, w] = freqz_m(h, 1);
    subplot(3, 1, 1)
    plot(n, h);
    title('������Ӧ');
    xlabel('n')
    ylabel('h');
    subplot(3, 1, 2);

    % �������ˣ���ô��Ƶ����Ӧ����ֱ�ӻ���Ƶ����ô��
    plot(w/pi, db);
    title('Ƶ����Ӧ(��Ƶ��������)');
    xlabel('\omega/\pi');
    ylabel('db');
    
    % ��Ƶ����
    subplot(3, 1, 3);
    plot(w/pi, pha);
    title('��Ƶ��������');
    xlabel('\omega/\pi');
    ylabel('pha');
elseif N == 45
    w_result = (hamming(N))';
%     w_result = (blackman(N))';
    h = hd .* w_result;
    [db, mag, pha, grd, w_result] = freqz_m(h, 1);
    subplot(2, 1, 1);
    % �������ˣ���ô��Ƶ����Ӧ����ֱ�ӻ���Ƶ����ô��
    plot(w_result/pi, db);
    title('Ƶ����Ӧ');
    xlabel('\omega/\pi');
    ylabel('db');
    subplot(2, 1, 2);
    plot(w_result/pi, pha);
    title('��Ƶ��������');
    xlabel('\omega/\pi');
    ylabel('pha');
end

% ������
% N = 15;
% wc = (wp+ws)/2;
% n = [0:1:N - 1];
% hd = ideal_lp(wc, N);
% w_result = (hamming(N))';
% h = hd .* w_result;
% [db, mag, pha, grd, w] = freqz_m(h, 1);
% 
% plot(w/pi, db, 'r');hold on;
% title('Ƶ����Ӧ(��Ƶ��������)');
% xlabel('\omega/\pi');
% ylabel('db');
% 
% N = 45;
% hd = ideal_lp(wc, N);
% w_result = (hamming(N))';
% h = hd .* w_result;   
% [db, mag, pha, grd, w_result] = freqz_m(h, 1);
% plot(w_result/pi, db);
% title('Ƶ����Ӧ');
% xlabel('\omega/\pi');
% ylabel('db');
% 
% 
% w_result = (blackman(N))';
% hd = ideal_lp(wc, N);
% h = hd .* w_result;
% [db, mag, pha, grd, w_result] = freqz_m(h, 1);
% plot(w_result/pi, db, 'k');
% title('Ƶ����Ӧ');
% xlabel('\omega/\pi');
% ylabel('db');
% legend('N=15,hamming','N=45,hamming', 'N=45, blackman');
