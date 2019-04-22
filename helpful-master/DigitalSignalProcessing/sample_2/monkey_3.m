% ���ִ�ͨ�˲���
% ͨƵ��  0.25~0.45p ͨ�����˥��Ϊ3db
% ����� < 0.15p ||  > 0.55p �����С˥��Ϊ15db
% ʹ��butterworth��ellipģ���ͨ�˲���
clear;
clc;
clf;
rp = 3;
rs = 15;
wp1 = 0.25*pi;% ---ws1---wp1---wp2---ws2
wp2 = 0.45*pi;
ws1 = 0.15*pi;
ws2 = 0.55*pi;
T = 0.001;
wp1 = wp1/T;    % ������Ӧ���䷨ת��
wp2 = wp2/T;
ws1 = ws1/T;
ws2 = ws2/T;
wp = [wp1, wp2];
ws = [ws1, ws2];
[n, wn] = buttord(wp, ws, rp, rs, 's'); % ������˹
[z, p, k] = buttap(n);
[b, a] = zp2tf(z, p, k);axis
w0 = sqrt(wp1*wp2);
bw = wp2-wp1;
[b1, a1] = lp2bp(b, a, w0, bw);
[db, mag, pha, grd, w] = freqz_m(bz, az);
subplot(2, 1, 1);
plot(w/pi, db);axis([0, 1, -50, 10])
title('������˹��ͨ�˲���')

% ��Բ�˲����Ļ���, ���¸�ֵ���¿�ʼ
wp1 = 0.25*pi;% ---ws1---wp1---wp2---ws2
wp2 = 0.45*pi;
ws1 = 0.15*pi;
ws2 = 0.55*pi;
wp1 = 2/T*tan(wp1/2); % ˫���Ա任��
wp2 = 2/T*tan(wp2/2);
ws1 = 2/T*tan(ws1/2);
ws2 = 2/T*tan(ws2/2);
[n, wn] = ellipord(wp, ws, rp, rs, 's');
[z, p, k] = ellipap(n, rp, rs);
[b, a] = zp2tf(z, p, k);
w0 = sqrt(wp1*wp2);
bw = wp2 - wp1;
[b1, a1] = lp2bp(b, a, w0, bw);
[bz, az] = bilinear(b1, a1, 1/T);
[db, mag, pha, grd, w] = freqz_m(bz, az);
subplot(2, 1, 2);
plot(w/pi, db);
axis([0, 1, -30, 10]);
title('��Բ�˲���')