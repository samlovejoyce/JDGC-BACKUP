function[data] = roadPowerSpectralDensity(v, fmin, fmax, Gd0, N, fs)
%
%
%
%
%
%
%
%
%v=1;
%fmin=0.5;								%时间频率 Hz
%fmax=30;								%时间频率 Hz

nmin=fmin/v;        					%空间频率 = fmin/v;
nmax=fmax/v;                			%空间频率 = fmax/v;

%Gd0=2^12;								%Gd0是计算Gd值公式中的一个常数 (2^N,N = 4,6,8,10,12,14,16,18)
%Gd0=2^4;
%N=2^14;                					%采样点数
%fs=200;                					%采样频率
deltf=fs/N;                				%时间域_频率分辨率

deltt=1/fs;                				%采样时间间隔
deltl=deltt*v;        					%采样距离间隔

deltf_r=deltf/v;                		%空间-频率分辨率

Neff=(nmax-nmin)/deltf_r;        		%有效频段内的采样点数
N0=nmin/deltf_r;        				%需要满足条件(N0+Neff<N/2)

k=0;
while(k*deltf_r<nmin)
k=k+1; 									%判断下截止频率所在位置
end

l=0;
while(l*deltf_r<nmax)
l=l+1; 									%判断上截止频率所在位置
end

Gd=[];									%Gd表示路面功率谱密度函数
x=[];

for ii=1:k
Gd(ii)=0;
x(ii)=0;
end

for ii=k+1:1:l+1
Gd(ii)=Gd0*((ii-1)*deltf_r/0.1)^(-2);    %空间频率下的功率谱
x(ii)=sqrt(N*Gd(ii)/2/deltl);            %频谱幅值
end

for ii=l+2:1:N/2
Gd(ii)=0;
x(ii)=0;
end

Gd(N/2+1)=0;
x(N/2+1)=0;

a=[];
xc=zeros(1,N);
for j=1:N/2
a(j)=2*pi*rand();
b(j)=cos(a(j))+i*sin(a(j));
xc(j)=b(j).*x(j);
end

xc(N/2+2:N)=fliplr(conj(xc(2:N/2)));     %共轭对称

xifft=ifft(xc);

for j=1:N
t(j)=(j-1)*deltl;
end

xaver=mean(xifft);
xsd=std(xifft);
xmax=max(xifft);

%数据返回
data.xifft = xifft;
data.t = t;
data.length = N;
