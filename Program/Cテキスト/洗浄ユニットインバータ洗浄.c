'��򃆃j�b�g�C���o�[�^���
'===================================================================================================================
'
'<<<<<<<	���j�b�g	>>>>>>>>
'
'===================================================================================================================
'
'	��򃆃j�b�g
'		
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    ��򃆃j�b�gAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    ��򃆃j�b�gAutoRun=OFF
    ��򃆃j�b�g����=ON
    ��򃆃j�b�gOrgErr=OFF
    ��򃆃j�b�gErr=OFF
    ��򃆃j�b�gEmg=OFF
    ��򃆃j�b�gstep=0
    ��򃆃j�b�gErrStep=0
    ��򃆃j�b�gOrgErrStep=0
    ��򃆃j�b�gEmgStep=0
	
	���=OFF
	
	ManualInite=1

	��򃆃j�b�g1�֎~=��򃆃j�b�g1�֎~
	��򃆃j�b�g2�֎~=��򃆃j�b�g2�֎~
	��򃆃j�b�g3�֎~=��򃆃j�b�g3�֎~
	��򃆃j�b�g4�֎~=��򃆃j�b�g4�֎~
	��򃆃j�b�g5�֎~=��򃆃j�b�g5�֎~

	
	if not(��򃆃j�b�g1�֎~) then
		mMC35_���|���vA=ON
	end if	
	if not(��򃆃j�b�g2�֎~) then
		mMC36_���|���vB=ON
	end if	
	if not(��򃆃j�b�g3�֎~) then
		mMC37_���|���vC=ON
	end if	
	if not(��򃆃j�b�g4�֎~) then
		mMC38_���|���vD=ON
	end if	
	if not(��򃆃j�b�g5�֎~) then
		mMC39_���|���vE=ON
	end if	
	
end if

if ldf(��򃆃j�b�g1�֎~) and not(THR35_���|���vA) then
	mMC35_���|���vA=ON
end if	
if ldf(��򃆃j�b�g2�֎~) and not(THR36_���|���vB) then
	mMC36_���|���vB=ON
end if	
if ldf(��򃆃j�b�g3�֎~) and not(THR37_���|���vC) then
	mMC37_���|���vC=ON
end if	
if ldf(��򃆃j�b�g4�֎~) and not(THR38_���|���vD) then
	mMC38_���|���vD=ON
end if	
if ldf(��򃆃j�b�g5�֎~) and not(THR39_���|���vE) then
	mMC39_���|���vE=ON
end if	


INV10_���|���vA�^�]=(mINV10_���|���vA�^�] or ejectINV10_���|���vA�^�] or extINV10_���|���vA�^�]) and not(pauseINV10_���|���vA�^�]) and not(EmgINV10_���|���vA�^�]) and timINV10_���|���vA�^�]
INV11_���|���vB�^�]=(mINV11_���|���vB�^�] or ejectINV11_���|���vB�^�] or extINV11_���|���vB�^�]) and not(pauseINV11_���|���vB�^�]) and not(EmgINV11_���|���vB�^�]) and timINV11_���|���vB�^�]
���ܓ����@=(mINV12_���|���vC�^�] or ejectINV12_���|���vC�^�] or extINV12_���|���vC�^�]) and not(pauseINV12_���|���vC�^�]) and not(EmgINV12_���|���vC�^�]) 
INV12_���|���vC�^�]=(mINV12_���|���vC�^�] or ejectINV12_���|���vC�^�] or extINV12_���|���vC�^�]) and not(pauseINV12_���|���vC�^�]) and not(EmgINV12_���|���vC�^�]) and timINV12_���|���vC�^�]
INV13_���|���vD�^�]=(mINV13_���|���vD�^�] or ejectINV13_���|���vD�^�] or extINV13_���|���vD�^�]) and not(pauseINV13_���|���vD�^�]) and not(EmgINV13_���|���vD�^�]) and timINV13_���|���vD�^�]
INV14_���|���vE�^�]=(mINV14_���|���vE�^�] or ejectINV14_���|���vE�^�] or extINV14_���|���vE�^�]) and not(pauseINV14_���|���vE�^�]) and not(EmgINV14_���|���vE�^�]) and timINV14_���|���vE�^�]



'--------------------------------------------------------
'���I����2�b�� FWD�M����OFF�ɂ��ăt���[���������������
'--------------------------------------------------------
tmr(timINV10_���|���vA�^�],#20)
tmr(timINV11_���|���vB�^�],#20)
tmr(timINV12_���|���vC�^�],#20)
tmr(timINV13_���|���vD�^�],#20)
tmr(timINV14_���|���vE�^�],#20)
	
if ldf(INV10_���|���vA���) then
	res(timINV10_���|���vA�^�])
end if
if ldf(INV11_���|���vB���) then
	res(timINV11_���|���vB�^�])
end if
if ldf(INV12_���|���vC���) then
	res(timINV12_���|���vC�^�])
end if
if ldf(INV13_���|���vD���) then
	res(timINV13_���|���vD�^�])
end if
if ldf(INV14_���|���vE���) then
	res(timINV14_���|���vE�^�])
end if

'===================================================================================================================
'�y ���_ �z
��򃆃j�b�gOrg= (XSW81_���t�^�������㏸�[A and XSW83_���t�^�������㏸�[B) or ��򃆃j�b�g1�֎~
��򃆃j�b�gOrg= ��򃆃j�b�gOrg and ((XSW86_���t�^�������㏸�[A and XSW88_���t�^�������㏸�[B) or ��򃆃j�b�g2�֎~) 
��򃆃j�b�gOrg= ��򃆃j�b�gOrg and ((XSW91_���t�^�������㏸�[A and XSW93_���t�^�������㏸�[B) or ��򃆃j�b�g3�֎~)
��򃆃j�b�gOrg= ��򃆃j�b�gOrg and ((XSW96_���t�^�������㏸�[A and XSW98_���t�^�������㏸�[B) or ��򃆃j�b�g4�֎~)
��򃆃j�b�gOrg= ��򃆃j�b�gOrg and ((XSW101_���t�^�������㏸�[A and XSW103_���t�^�������㏸�[B) or ��򃆃j�b�g5�֎~)

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	��򃆃j�b�gEmg=ON
	��򃆃j�b�gEmgStep=1
end if


if ��򃆃j�b�gEmgStep<>0 then
	
	pauseINV10_���|���vA�^�]=ON
	pauseINV11_���|���vB�^�]=ON
	pauseINV12_���|���vC�^�]=ON
	pauseINV13_���|���vD�^�]=ON
	pauseINV14_���|���vE�^�]=ON

	��򃆃j�b�gEmg=ON

else
	pauseINV10_���|���vA�^�]=not(FLT1_�^���N������m�m�F) or not(FLT2_�^���N����) or ��򃆃j�b�g1�֎~
	pauseINV11_���|���vB�^�]=not(FLT3_�^���N������m�m�F) or not(FLT4_�^���N����) or ��򃆃j�b�g2�֎~
	pauseINV12_���|���vC�^�]=not(FLT5_�^���N������m�m�F) or not(FLT6_�^���N����) or ��򃆃j�b�g3�֎~
	pauseINV13_���|���vD�^�]=not(FLT7_�^���N������m�m�F) or not(FLT8_�^���N����) or ��򃆃j�b�g4�֎~
	pauseINV14_���|���vE�^�]=not(FLT9_�^���N������m�m�F) or not(FLT10_�^���N����) or ��򃆃j�b�g5�֎~

	��򃆃j�b�gEmg=OFF

end if
'===================================================================================================================
'���|���v�����؂�ւ�

	if CR2008 then '�d��ON������������
		if not(��򃆃j�b�g1�֎~) then
			mMC35_���|���vA=ON
		end if	
		if not(��򃆃j�b�g2�֎~) then
			mMC36_���|���vB=ON
		end if	
		if not(��򃆃j�b�g3�֎~) then
			mMC37_���|���vC=ON
		end if	
		if not(��򃆃j�b�g4�֎~) then
			mMC38_���|���vD=ON
		end if	
		if not(��򃆃j�b�g5�֎~) then
			mMC39_���|���vE=ON
		end if	
	end if

	if not(MC35_���|���vA) then
		mINV10_���|���vA�^�]=OFF
		INV10_���|���vA���=OFF
	else if not(MC36_���|���vB) then
		mINV11_���|���vB�^�]=OFF
		INV11_���|���vB���=OFF	
	else if not(MC37_���|���vC) then
		mINV12_���|���vC�^�]=OFF
		INV12_���|���vC���=OFF		
	else if not(MC38_���|���vD) then
		mINV13_���|���vD�^�]=OFF
		INV13_���|���vD���=OFF		
	else if not(MC39_���|���vE) then
		mINV14_���|���vE�^�]=OFF
		INV14_���|���vE���=OFF		
	end if

	tmr(MC35_���|���vA,tim_INV10_���|���vA�d��dly,#30)
	tmr(MC36_���|���vB,tim_INV11_���|���vB�d��dly,#30)
	tmr(MC37_���|���vC,tim_INV12_���|���vC�d��dly,#30)
	tmr(MC38_���|���vD,tim_INV13_���|���vD�d��dly,#30)
	tmr(MC39_���|���vE,tim_INV14_���|���vE�d��dly,#30)

	'----------------------------------------------------------------------------------------------------------------------------------
	'----- INV10_���|���vA�ُ�  �k�����C���o�[�^����ُ̈�M���ړ_��A�ړ_ -----
	if ldp(tim_INV10_���|���vA�d��dly and INV10_���|���vA�ُ� and not(��򃆃j�b�g1�֎~)) then '�C���o�[�^�̃A���[���o�͌��m
	 	almINV10_���|���vA�ُ�=ON
		��򃆃j�b�gErrStep=1
	else if ldp(tim_INV11_���|���vB�d��dly and INV11_���|���vB�ُ� and not(��򃆃j�b�g2�֎~)) then '�C���o�[�^�̃A���[���o�͌��m
		almINV11_���|���vB�ُ�=ON
		��򃆃j�b�gErrStep=1
	else if ldp(tim_INV12_���|���vC�d��dly and INV12_���|���vC�ُ� and not(��򃆃j�b�g3�֎~)) then '�C���o�[�^�̃A���[���o�͌��m
		almINV12_���|���vC�ُ�=ON
		��򃆃j�b�gErrStep=1
	else if ldp(tim_INV13_���|���vD�d��dly and INV13_���|���vD�ُ� and not(��򃆃j�b�g4�֎~)) then '�C���o�[�^�̃A���[���o�͌��m
		almINV13_���|���vD�ُ�=ON
		��򃆃j�b�gErrStep=1
	else if ldp(tim_INV14_���|���vE�d��dly and INV14_���|���vE�ُ� and not(��򃆃j�b�g5�֎~)) then '�C���o�[�^�̃A���[���o�͌��m
		almINV14_���|���vE�ُ�=ON
		��򃆃j�b�gErrStep=1
	end if
	'----------------------------------------------------------------------------------------------------------------------------------
		
	if INV10_���|���vA��� then
		setS05c10=���|���vA��򐅈�
	else
		setS05c10=���|���vA�ҋ@����
	end if
	setS08c10=#10 '���|���vA�����オ�莞��
	setS09c10=#30
	
	if INV11_���|���vB��� then
		setS05c11=���|���vB��򐅈�
	else
		setS05c11=���|���vB�ҋ@����
	end if
	setS08c11=#10 '���|���vB�����オ�莞��
	setS09c11=#30
	
	if INV12_���|���vC��� then
		setS05c12=���|���vC��򐅈�
	else
		setS05c12=���|���vC�ҋ@����
	end if
	setS08c12=#10 '���|���vC�����オ�莞��
	setS09c12=#30
	
	if INV13_���|���vD��� then
		setS05c13=���|���vD��򐅈�
	else
		setS05c13=���|���vD�ҋ@����
	end if
	setS08c13=#10 '���|���vD�����オ�莞��
	setS09c13=#30
	
	if INV14_���|���vE��� then
		setS05c14=���|���vE��򐅈�
	else
		setS05c14=���|���vE�ҋ@����
	end if
	setS08c14=#10 '���|���vE�����オ�莞��
	setS09c14=#30

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z
'---- ��򃆃j�b�g1 ----
tmr(SV67_���t�^���������~A and not(LatchXSW82_���t�^���������~�[A) and not(pnlPBXSW82_���t�^���������~�[A),tim_XSW82_���t�^���������~�[A,#80)
if ldp(SV67_���t�^���������~A) then
	res(passtimXSW82_���t�^���������~�[A)
end if
tmr(not(SV67_���t�^���������~A) and not(XSW81_���t�^�������㏸�[A) and not(pnlPBXSW81_���t�^�������㏸�[A),tim_XSW81_���t�^�������㏸�[A,#80)
if ldf(SV67_���t�^���������~A) then
	res(passtimXSW81_���t�^�������㏸�[A)
end if

tmr(SV68_���t�^���������~B and not(LatchXSW84_���t�^���������~�[B) and not(pnlPBXSW84_���t�^���������~�[B),tim_XSW84_���t�^���������~�[B,#80)
if ldp(SV68_���t�^���������~B) then
	res(passtimXSW84_���t�^���������~�[B)
end if

tmr(not(SV68_���t�^���������~B) and not(XSW83_���t�^�������㏸�[B) and not(pnlPBXSW83_���t�^�������㏸�[B),tim_XSW83_���t�^�������㏸�[B,#80)
if ldf(SV68_���t�^���������~B) then
	res(passtimXSW83_���t�^�������㏸�[B)
end if

'---- ��򃆃j�b�g2 ----
tmr(SV73_���t�^���������~A and not(LatchXSW87_���t�^���������~�[A) and not(pnlPBXSW87_���t�^���������~�[A),tim_XSW87_���t�^���������~�[A,#80)
if ldp(SV73_���t�^���������~A) then
	res(passtimXSW87_���t�^���������~�[A)
end if
tmr(not(SV73_���t�^���������~A) and not(XSW86_���t�^�������㏸�[A) and not(pnlPBXSW86_���t�^�������㏸�[A),tim_XSW86_���t�^�������㏸�[A,#80)
if ldf(SV73_���t�^���������~A) then
	res(passtimXSW86_���t�^�������㏸�[A)
end if

tmr(SV74_���t�^���������~B and not(LatchXSW89_���t�^���������~�[B) and not(pnlPBXSW89_���t�^���������~�[B),tim_XSW89_���t�^���������~�[B,#80)
if ldp(SV74_���t�^���������~B) then
	res(passtimXSW89_���t�^���������~�[B)
end if
tmr(not(SV74_���t�^���������~B) and not(XSW88_���t�^�������㏸�[B) and not(pnlPBXSW88_���t�^�������㏸�[B),tim_XSW88_���t�^�������㏸�[B,#80)
if ldf(SV74_���t�^���������~B) then
	res(passtimXSW88_���t�^�������㏸�[B)
end if

'---- ��򃆃j�b�g3 ----
tmr(SV79_���t�^���������~A and not(LatchXSW92_���t�^���������~�[A) and not(pnlPBXSW92_���t�^���������~�[A),tim_XSW92_���t�^���������~�[A,#80)
if ldp(SV79_���t�^���������~A) then
	res(passtimXSW92_���t�^���������~�[A)
end if
tmr(not(SV79_���t�^���������~A) and not(XSW91_���t�^�������㏸�[A) and not(pnlPBXSW91_���t�^�������㏸�[A),tim_XSW91_���t�^�������㏸�[A,#80)
if ldf(SV79_���t�^���������~A) then
	res(XSW91_���t�^�������㏸�[A)
end if

tmr(SV80_���t�^���������~B and not(LatchXSW94_���t�^���������~�[B) and not(pnlPBXSW94_���t�^���������~�[B),tim_XSW94_���t�^���������~�[B,#80)
if ldp(SV80_���t�^���������~B) then
	res(passtimXSW94_���t�^���������~�[B)
end if

tmr(not(SV80_���t�^���������~B) and not(XSW93_���t�^�������㏸�[B) and not(pnlPBXSW93_���t�^�������㏸�[B),tim_XSW93_���t�^�������㏸�[B,#80)
if ldf(SV80_���t�^���������~B) then
	res(passtimXSW93_���t�^�������㏸�[B)
end if

'---- ��򃆃j�b�g4 ----
tmr(SV85_���t�^���������~A and not(LatchXSW97_���t�^���������~�[A) and not(pnlPBXSW97_���t�^���������~�[A),tim_XSW97_���t�^���������~�[A,#80)
if ldp(SV85_���t�^���������~A) then
	res(passtimXSW97_���t�^���������~�[A)
end if
tmr(not(SV85_���t�^���������~A) and not(XSW96_���t�^�������㏸�[A) and not(pnlPBXSW96_���t�^�������㏸�[A),tim_XSW96_���t�^�������㏸�[A,#80)
if ldf(SV85_���t�^���������~A) then
	res(passtimXSW96_���t�^�������㏸�[A)
end if

tmr(SV86_���t�^���������~B and not(LatchXSW99_���t�^���������~�[B) and not(pnlPBXSW99_���t�^���������~�[B),tim_XSW99_���t�^���������~�[B,#80)
if ldp(SV86_���t�^���������~B) then
	res(passtimXSW99_���t�^���������~�[B)
end if
tmr(not(SV86_���t�^���������~B) and not(XSW98_���t�^�������㏸�[B) and not(pnlPBXSW98_���t�^�������㏸�[B),tim_XSW98_���t�^�������㏸�[B,#80)
if ldf(SV86_���t�^���������~B) then
	res(passtimXSW98_���t�^�������㏸�[B)
end if

'---- ��򃆃j�b�g5 ----
tmr(SV91_���t�^���������~A and not(LatchXSW102_���t�^���������~�[A) and not(pnlPBXSW102_���t�^���������~�[A),tim_XSW102_���t�^���������~�[A,#80)
if ldp(SV91_���t�^���������~A) then
	res(passtimXSW102_���t�^���������~�[A)
end if
tmr(not(SV91_���t�^���������~A) and not(XSW101_���t�^�������㏸�[A) and not(pnlPBXSW101_���t�^�������㏸�[A),tim_XSW101_���t�^�������㏸�[A,#80)
if ldf(SV91_���t�^���������~A) then
	res(passtimXSW101_���t�^�������㏸�[A)
end if

tmr(SV92_���t�^���������~B and not(LatchXSW104_���t�^���������~�[B) and not(pnlPBXSW104_���t�^���������~�[B),tim_XSW104_���t�^���������~�[B,#80)
if ldp(SV92_���t�^���������~B) then
	res(passtimXSW104_���t�^���������~�[B)
end if
tmr(not(SV92_���t�^���������~B) and not(XSW103_���t�^�������㏸�[B) and not(pnlPBXSW103_���t�^�������㏸�[B),tim_XSW103_���t�^�������㏸�[B,#80)
if ldf(SV92_���t�^���������~B) then
	res(passtimXSW103_���t�^�������㏸�[B)
end if


if ldp(tim_XSW82_���t�^���������~�[A.B) and not(��򃆃j�b�g1�֎~) then
	almXSW82_���t�^���������~�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW81_���t�^�������㏸�[A.B)  and not(��򃆃j�b�g1�֎~) then
	almXSW81_���t�^�������㏸�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW84_���t�^���������~�[B.B)  and not(��򃆃j�b�g1�֎~) then
	almXSW84_���t�^���������~�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW83_���t�^�������㏸�[B.B)  and not(��򃆃j�b�g1�֎~) then
	almXSW83_���t�^�������㏸�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW87_���t�^���������~�[A.B)  and not(��򃆃j�b�g2�֎~) then
	almXSW87_���t�^���������~�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW86_���t�^�������㏸�[A.B)  and not(��򃆃j�b�g2�֎~) then
	almXSW86_���t�^�������㏸�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW89_���t�^���������~�[B.B)  and not(��򃆃j�b�g2�֎~) then
	almXSW89_���t�^���������~�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW88_���t�^�������㏸�[B.B)  and not(��򃆃j�b�g2�֎~) then
	almXSW88_���t�^�������㏸�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW92_���t�^���������~�[A.B)  and not(��򃆃j�b�g3�֎~) then
	almXSW92_���t�^���������~�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW91_���t�^�������㏸�[A.B)  and not(��򃆃j�b�g3�֎~) then
	almXSW91_���t�^�������㏸�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW94_���t�^���������~�[B.B)  and not(��򃆃j�b�g3�֎~) then
	almXSW94_���t�^���������~�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW93_���t�^�������㏸�[B.B)  and not(��򃆃j�b�g3�֎~) then
	almXSW93_���t�^�������㏸�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW97_���t�^���������~�[A.B)  and not(��򃆃j�b�g4�֎~) then
	almXSW97_���t�^���������~�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW96_���t�^�������㏸�[A.B)  and not(��򃆃j�b�g4�֎~) then
	almXSW96_���t�^�������㏸�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW99_���t�^���������~�[B.B)  and not(��򃆃j�b�g4�֎~) then
	almXSW99_���t�^���������~�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW98_���t�^�������㏸�[B.B)  and not(��򃆃j�b�g4�֎~) then
	almXSW98_���t�^�������㏸�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW102_���t�^���������~�[A.B)  and not(��򃆃j�b�g5�֎~) then
	almXSW102_���t�^���������~�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW101_���t�^�������㏸�[A.B)  and not(��򃆃j�b�g5�֎~) then
	almXSW101_���t�^�������㏸�[A=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW104_���t�^���������~�[B.B)  and not(��򃆃j�b�g5�֎~) then
	almXSW104_���t�^���������~�[B=ON
	��򃆃j�b�gErrStep=1

else if ldp(tim_XSW103_���t�^�������㏸�[B.B)  and not(��򃆃j�b�g5�֎~) then
	almXSW103_���t�^�������㏸�[B=ON
	��򃆃j�b�gErrStep=1

end if

'===================================================================================================================
tmr(not(FLT2_�^���N����),nottimdly_FLT2_�^���N����,#30)
tmr(not(FLT4_�^���N����),nottimdly_FLT4_�^���N����,#30)
tmr(not(FLT6_�^���N����),nottimdly_FLT6_�^���N����,#30)
tmr(not(FLT8_�^���N����),nottimdly_FLT8_�^���N����,#30)
tmr(not(FLT10_�^���N����),nottimdly_FLT10_�^���N����,#30)

tmr(not(FLT1_�^���N���),nottimdly_FLT1_�^���N���,#200)
tmr(not(FLT3_�^���N���),nottimdly_FLT3_�^���N���,#200)
tmr(not(FLT5_�^���N���),nottimdly_FLT5_�^���N���,#200)
tmr(not(FLT7_�^���N���),nottimdly_FLT7_�^���N���,#200)
tmr(not(FLT9_�^���N���),nottimdly_FLT9_�^���N���,#200)


if FLT1_�^���N��� then
	FLT1_�^���N������m�m�F=ON
else if not(FLT2_�^���N����) then
	FLT1_�^���N������m�m�F=OFF
end if

if FLT3_�^���N��� then
	FLT3_�^���N������m�m�F=ON
else if not(FLT4_�^���N����) then
	FLT3_�^���N������m�m�F=OFF
end if

if FLT5_�^���N��� then
	FLT5_�^���N������m�m�F=ON
else if not(FLT6_�^���N����) then
	FLT5_�^���N������m�m�F=OFF
end if

if FLT7_�^���N��� then
	FLT7_�^���N������m�m�F=ON
else if not(FLT8_�^���N����) then
	FLT7_�^���N������m�m�F=OFF
end if

if FLT9_�^���N��� then
	FLT9_�^���N������m�m�F=ON
else if not(FLT10_�^���N����) then
	FLT9_�^���N������m�m�F=OFF
end if

tmr(PH46_�t�^���m or PH45_�����m,tim_�������t�^�����m,20) '�蓮�^�]���̐��������[�N���m

'===================================================================================================================
'PL�C���W�P�[�^

	PBL25_���@�P���^�]=�����T�C�N��flg

'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: ��򃆃j�b�gAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: ��򃆃j�b�gAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: ��򃆃j�b�gEmg	���̏��~


if not(��򃆃j�b�gEmg) then  
	
	if ��򃆃j�b�gErrStep=0  then

	if not(��򃆃j�b�gOrgErr) then

	if (��򃆃j�b�gAutoMode and ��������AutoMode ) or ��򃆃j�b�gstep<>0  then
	
		if not(��򃆃j�b�gAutoMode and ��������AutoMode ) then
			��򃆃j�b�gAutoRun=OFF
		end if

		'�������d����, �d�グ�d����
		if ��򃆃j�b�gAutoRun then	
			if �������֎~ then
				mSV97_�������d����=OFF
				mSV98_�d�グ�d����=OFF
			else
				mSV97_�������d����=ON
				mSV98_�d�グ�d����=ON
			end if
		else
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF
		end if
				
				
		if ManualInite=1 then
			PBL43_���|���v=OFF
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF

			mINV10_���|���vA�^�]=OFF
			mINV11_���|���vB�^�]=OFF
			mINV12_���|���vC�^�]=OFF
			mINV13_���|���vD�^�]=OFF
			mINV14_���|���vE�^�]=OFF		

			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF


			tmp���|���v=OFF
			tmp1SV97_�������d����=OFF
			tmp1SV98_�d�グ�d����=OFF
			tmp1INV10_���|���vA�^�]=OFF
			tmp1INV11_���|���vB�^�]=OFF
			tmp1INV12_���|���vC�^�]=OFF
			tmp1INV13_���|���vD�^�]=OFF
			tmp1INV14_���|���vE�^�]=OFF
			
			tmp2SV97_�������d����=OFF
			tmp2SV98_�d�グ�d����=OFF
			tmp2INV10_���|���vA�^�]=OFF
			tmp2INV11_���|���vB�^�]=OFF
			tmp2INV12_���|���vC�^�]=OFF
			tmp2INV13_���|���vD�^�]=OFF
			tmp2INV14_���|���vE�^�]=OFF

			ManualInite=0
		end if
		

	'===================================================================================================================
	'�y �v���Z�X���� �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ��򃆃j�b�gstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
			��򃆃j�b�gStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' ��ƍH����U�蕪����
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if ��򃆃j�b�gAutoRun or �����T�C�N��flg then
				��򃆃j�b�gStatusMsg=#70	'	�ҋ@��
				mINV10_���|���vA�^�]=ON
				mINV11_���|���vB�^�]=ON
				mINV12_���|���vC�^�]=ON
				mINV13_���|���vD�^�]=ON
				mINV14_���|���vE�^�]=ON

				if ��� then
					��򃆃j�b�gstep=200
				else
					inc(��򃆃j�b�gstep)
				end if


			else

				mINV10_���|���vA�^�]=OFF
				mINV11_���|���vB�^�]=OFF
				mINV12_���|���vC�^�]=OFF
				mINV13_���|���vD�^�]=OFF
				mINV14_���|���vE�^�]=OFF

				mSV97_�������d����=OFF
				mSV98_�d�グ�d����=OFF
				
				INV10_���|���vA���=OFF
				INV11_���|���vB���=OFF
				INV12_���|���vC���=OFF
				INV13_���|���vD���=OFF
				INV14_���|���vE���=OFF
				
				if ��� then
					������=ON
					��򃆃j�b�gstep=200
				else
					��򃆃j�b�gstep=0
				end if
			end if
		
		
		
		case 2
		' [ �W�J�}�ړ���~�m�F ]
			if ��򊮗�=OFF and  ���R���x�A�������쒆=OFF then
				inc(��򃆃j�b�gstep)
			else
				��򃆃j�b�gstep=1
			end if
		
		case 3
		' [ ���j�b�g�����o ]
			if ��򃆃j�b�g���� then
				inc(��򃆃j�b�gstep) '�v���Z�X����
			else
				��򊮗�=ON
				��򃆃j�b�gstep=1
			end if
		
		case 4
			if ��򃆃j�b�gOrg then
				��򃆃j�b�gstep=100
			else
				��򃆃j�b�gstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'�v���Z�X����
		case 100
			tmp��򃆃j�b�g1�֎~=��򃆃j�b�g1�֎~
			tmp��򃆃j�b�g2�֎~=��򃆃j�b�g2�֎~
			tmp��򃆃j�b�g3�֎~=��򃆃j�b�g3�֎~
			tmp��򃆃j�b�g4�֎~=��򃆃j�b�g4�֎~
			tmp��򃆃j�b�g5�֎~=��򃆃j�b�g5�֎~
		
			���H���I��=OFF
			��򃆃j�b�gStatusMsg=#72	'	�^�]��
			
			if not(tmp��򃆃j�b�g1�֎~) then
				if shiftreg���t�^����1=$80 then '�����o			
					mSV68_���t�^���������~B=ON
				else if shiftreg���t�^����1=$40 then '�t�^���o
					mSV67_���t�^���������~A=ON
					mSV68_���t�^���������~B=ON
				end if
			else
				mSV67_���t�^���������~A=OFF
				mSV68_���t�^���������~B=OFF
			end if


			if not(tmp��򃆃j�b�g2�֎~) then
				if shiftreg���t�^����2=$80 then '�����o			
					mSV74_���t�^���������~B=ON
				else if shiftreg���t�^����2=$40 then '�t�^���o
					mSV73_���t�^���������~A=ON
					mSV74_���t�^���������~B=ON
				end if
			else
				mSV73_���t�^���������~A=OFF
				mSV74_���t�^���������~B=OFF
			end if
			
			if not(tmp��򃆃j�b�g3�֎~) then
				if shiftreg���t�^����3=$80 then '�����o			
					mSV80_���t�^���������~B=ON
				else if shiftreg���t�^����3=$40 then '�t�^���o
					mSV79_���t�^���������~A=ON
					mSV80_���t�^���������~B=ON
				end if
			else
				mSV79_���t�^���������~A=OFF
				mSV80_���t�^���������~B=OFF
			end if

			if not(tmp��򃆃j�b�g4�֎~) then
				if shiftreg���t�^����4=$80 then '�����o			
					mSV86_���t�^���������~B=ON
				else if shiftreg���t�^����4=$40 then '�t�^���o
					mSV85_���t�^���������~A=ON
					mSV86_���t�^���������~B=ON
				end if
			else
				mSV85_���t�^���������~A=OFF
				mSV86_���t�^���������~B=OFF
			end if
			
			if not(tmp��򃆃j�b�g5�֎~) then
				if shiftreg���t�^����5=$80 then '�����o			
					mSV92_���t�^���������~B=ON
				else if shiftreg���t�^����5=$40 then '�t�^���o
					mSV91_���t�^���������~A=ON
					mSV92_���t�^���������~B=ON
				end if
			else
				mSV91_���t�^���������~A=OFF
				mSV92_���t�^���������~B=OFF
			end if
			
			LatchXSW82_���t�^���������~�[A=OFF
			LatchXSW84_���t�^���������~�[B=OFF
			LatchXSW87_���t�^���������~�[A=OFF
			LatchXSW89_���t�^���������~�[B=OFF
			LatchXSW92_���t�^���������~�[A=OFF
			LatchXSW94_���t�^���������~�[B=OFF
			LatchXSW97_���t�^���������~�[A=OFF
			LatchXSW99_���t�^���������~�[B=OFF
			LatchXSW102_���t�^���������~�[A=OFF
			LatchXSW104_���t�^���������~�[B=OFF
		
			inc(��򃆃j�b�gstep)
			
		case 101
			if tmp��򃆃j�b�g1�֎~ then
				inc(��򃆃j�b�gstep)			
			else if shiftreg���t�^����1=$80 and mSV67_���t�^���������~A then '�����o			
				if (LatchXSW82_���t�^���������~�[A or passXSW82_���t�^���������~�[A) then
					inc(��򃆃j�b�gstep)
				end if
			else if shiftreg���t�^����1=$40 and mSV67_���t�^���������~A and mSV68_���t�^���������~B then '�t�^���o
				if (LatchXSW82_���t�^���������~�[A or passXSW82_���t�^���������~�[A) and (LatchXSW84_���t�^���������~�[B or passXSW84_���t�^���������~�[B) then
					inc(��򃆃j�b�gstep)
				end if
			else 
				inc(��򃆃j�b�gstep)
			end if
		
		case 102
			if tmp��򃆃j�b�g2�֎~ then
				inc(��򃆃j�b�gstep)			
			else if shiftreg���t�^����2=$80 and mSV73_���t�^���������~A then '�����o			
				if (LatchXSW87_���t�^���������~�[A or passXSW87_���t�^���������~�[A) then
					inc(��򃆃j�b�gstep)
				end if
			else if shiftreg���t�^����2=$40 and mSV73_���t�^���������~A and mSV74_���t�^���������~B then '�t�^���o
				if (LatchXSW87_���t�^���������~�[A or passXSW87_���t�^���������~�[A)  and (LatchXSW89_���t�^���������~�[B or passXSW89_���t�^���������~�[B) then
					inc(��򃆃j�b�gstep)
				end if
			else
				inc(��򃆃j�b�gstep)
			end if
		
		case 103
			if tmp��򃆃j�b�g3�֎~ then
				inc(��򃆃j�b�gstep)			
			else if shiftreg���t�^����3=$80 and mSV79_���t�^���������~A then '�����o			
				if (LatchXSW92_���t�^���������~�[A or passXSW92_���t�^���������~�[A) then
					inc(��򃆃j�b�gstep)
				end if
			else if shiftreg���t�^����3=$40 and mSV79_���t�^���������~A and mSV80_���t�^���������~B then '�t�^���o
				if (LatchXSW92_���t�^���������~�[A or passXSW92_���t�^���������~�[A) and (LatchXSW94_���t�^���������~�[B or passXSW94_���t�^���������~�[B) then
					inc(��򃆃j�b�gstep)
				end if
			else
				inc(��򃆃j�b�gstep)
			end if		
		
		case 104
			if tmp��򃆃j�b�g4�֎~ then
				inc(��򃆃j�b�gstep)			
			else if shiftreg���t�^����4=$80 and mSV85_���t�^���������~A then '�����o	
				if (LatchXSW97_���t�^���������~�[A or passXSW97_���t�^���������~�[A) then
					inc(��򃆃j�b�gstep)
				end if			
			else if shiftreg���t�^����4=$40 and mSV85_���t�^���������~A and mSV86_���t�^���������~B then '�t�^���o
				if (LatchXSW97_���t�^���������~�[A or passXSW97_���t�^���������~�[A) and (LatchXSW99_���t�^���������~�[B or passXSW99_���t�^���������~�[B) then
					inc(��򃆃j�b�gstep)
				end if			
			else
				inc(��򃆃j�b�gstep)
			end if
		
		case 105
			if tmp��򃆃j�b�g5�֎~ then
				inc(��򃆃j�b�gstep)			
			else if shiftreg���t�^����5=$80 and mSV91_���t�^���������~A then '�����o			
				if (LatchXSW102_���t�^���������~�[A or passXSW102_���t�^���������~�[A) then
					inc(��򃆃j�b�gstep)
				end if			
			else if shiftreg���t�^����5=$40 and mSV91_���t�^���������~A and mSV92_���t�^���������~B then '�t�^���o
				if (LatchXSW102_���t�^���������~�[A or passXSW102_���t�^���������~�[A)  and (LatchXSW104_���t�^���������~�[B or passXSW104_���t�^���������~�[B) then
					inc(��򃆃j�b�gstep)
				end if			
			else
				inc(��򃆃j�b�gstep)
			end if
		
		case 106
			tim_procstep_val=#5
			res(tim_procstep)
			inc(��򃆃j�b�gstep)
		
		
		case 107
			if tim_procstep.B then
				inc(��򃆃j�b�gstep)
			end if
		
		case 108
			if tmp��򃆃j�b�g1�֎~ then
				INV10_���|���vA���=OFF
			else if shiftreg���t�^����1=$80 then '�����o			
				INV10_���|���vA���=ON
			else if shiftreg���t�^����1=$40 then '�t�^���o
				INV10_���|���vA���=ON
			end if
			
			if tmp��򃆃j�b�g2�֎~ then
				INV11_���|���vB���=OFF
			else if shiftreg���t�^����2=$80 then '�����o			
				INV11_���|���vB���=ON
			else if shiftreg���t�^����2=$40 then '�t�^���o
				INV11_���|���vB���=ON
			end if
			
			if tmp��򃆃j�b�g3�֎~ then
				INV12_���|���vC���=OFF
			else if shiftreg���t�^����3=$80 then '�����o			
				INV12_���|���vC���=ON
			else if shiftreg���t�^����3=$40 then '�t�^���o
				INV12_���|���vC���=ON
			end if
			
			if tmp��򃆃j�b�g4�֎~ then
				INV13_���|���vD���=OFF
			else if shiftreg���t�^����4=$80 then '�����o			
				INV13_���|���vD���=ON
			else if shiftreg���t�^����4=$40 then '�t�^���o
				INV13_���|���vD���=ON
			end if
			
			if tmp��򃆃j�b�g5�֎~ then
				INV14_���|���vE���=OFF			
			else if shiftreg���t�^����5=$80 then '�����o			
				INV14_���|���vE���=ON
			else if shiftreg���t�^����5=$40 then '�t�^���o
				INV14_���|���vE���=ON
			end if

			
			
			tim_procstep_val=DM_��򎞊�
			res(tim_procstep)
			
			���=ON
			������=OFF
			
			��򃆃j�b�gstep=200

		case 200
			'if  ( (�����T�C�N��flg or ������)  and (tim_procstep.B or (�����T�C�N��flg and tim_�������t�^�����m)) ) or (not(�����T�C�N��flg or ������) and (�����������r�o�v�� or ���H���I��)) then
			if  ( (�����T�C�N��flg or ������)  and (tim_procstep.B or (�����T�C�N��flg and tim_�������t�^�����m)) ) or (not(�����T�C�N��flg or ������) and �����������r�o�v��) then
				INV10_���|���vA���=OFF
				INV11_���|���vB���=OFF
				INV12_���|���vC���=OFF
				INV13_���|���vD���=OFF
				INV14_���|���vE���=OFF
				
				tim_procstep_val=40
				res(tim_procstep)
				inc(��򃆃j�b�gstep)
			else
				��򃆃j�b�gstep=1
			end if
		
		case 201
			���H���I��=OFF

			if tim_procstep.B then
				mSV67_���t�^���������~A=OFF
				mSV73_���t�^���������~A=OFF
				mSV79_���t�^���������~A=OFF
				mSV85_���t�^���������~A=OFF
				mSV91_���t�^���������~A=OFF

				inc(��򃆃j�b�gstep)
			end if
		
		case 202
			if (XSW81_���t�^�������㏸�[A or passXSW81_���t�^�������㏸�[A or tmp��򃆃j�b�g1�֎~) then
				if (XSW86_���t�^�������㏸�[A or passXSW86_���t�^�������㏸�[A or tmp��򃆃j�b�g2�֎~) then
					if (XSW91_���t�^�������㏸�[A or passXSW91_���t�^�������㏸�[A  or tmp��򃆃j�b�g3�֎~) then
						if (XSW96_���t�^�������㏸�[A or passXSW96_���t�^�������㏸�[A  or tmp��򃆃j�b�g4�֎~) then
							if (XSW101_���t�^�������㏸�[A or passXSW101_���t�^�������㏸�[A or tmp��򃆃j�b�g5�֎~)then
								inc(��򃆃j�b�gstep)
							end if
						end if
					end if
				end if
			end if		
		
		case 203
				tim_procstep_val=0
				res(tim_procstep)
				inc(��򃆃j�b�gstep)
		
		case 204
			if tim_procstep.B then
				inc(��򃆃j�b�gstep)			
			end if
		
		case 205
				mSV68_���t�^���������~B=OFF
				mSV74_���t�^���������~B=OFF
				mSV80_���t�^���������~B=OFF
				mSV86_���t�^���������~B=OFF
				mSV92_���t�^���������~B=OFF
				inc(��򃆃j�b�gstep)
		
		case 206			
			if (XSW83_���t�^�������㏸�[B or passXSW83_���t�^�������㏸�[B or tmp��򃆃j�b�g1�֎~) then
				if (XSW88_���t�^�������㏸�[B or passXSW88_���t�^�������㏸�[B or tmp��򃆃j�b�g2�֎~) then
					if (XSW93_���t�^�������㏸�[B or passXSW93_���t�^�������㏸�[B or tmp��򃆃j�b�g3�֎~) then
						if (XSW98_���t�^�������㏸�[B or passXSW98_���t�^�������㏸�[B or tmp��򃆃j�b�g4�֎~) then
							if (XSW103_���t�^�������㏸�[B or passXSW103_���t�^�������㏸�[B or tmp��򃆃j�b�g5�֎~) then
								inc(��򃆃j�b�gstep)
							end if
						end if
					end if
				end if
			end if
			
		case 207
			tim_procstep_val=0
			res(tim_procstep)
			inc(��򃆃j�b�gstep)
			
		case 208
			if tim_procstep.B then
				inc(��򃆃j�b�gstep)	
			end if
		
		case 209
			��򊮗�=ON
			���=OFF
			�����T�C�N��flg=OFF
			��򃆃j�b�gstep=1
			
		end select

	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else
		'res(tim_XSW82_���t�^���������~�[A)
		'res(tim_XSW81_���t�^�������㏸�[A)
		'res(tim_XSW84_���t�^���������~�[B)
		'res(tim_XSW83_���t�^�������㏸�[B)
		'res(tim_XSW87_���t�^���������~�[A)
		'res(tim_XSW86_���t�^�������㏸�[A)
		'res(tim_XSW89_���t�^���������~�[B)
		'res(tim_XSW88_���t�^�������㏸�[B)
		'res(tim_XSW92_���t�^���������~�[A)
		'res(tim_XSW91_���t�^�������㏸�[A)
		'res(tim_XSW94_���t�^���������~�[B)
		'res(tim_XSW93_���t�^�������㏸�[B)
		'res(tim_XSW97_���t�^���������~�[A)
		'res(tim_XSW96_���t�^�������㏸�[A)
		'res(tim_XSW99_���t�^���������~�[B)
		'res(tim_XSW98_���t�^�������㏸�[B)
		'res(tim_XSW102_���t�^���������~�[A)
		'res(tim_XSW101_���t�^�������㏸�[A)
		'res(tim_XSW104_���t�^���������~�[B)
		'res(tim_XSW103_���t�^�������㏸�[B)

		��򃆃j�b�gAutoRun=OFF
		
		��򃆃j�b�gstep=0 '�I��
		
		��򊮗�=OFF
		
		if ManualInite=0 then
			PBL43_���|���v=OFF
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF

			mINV10_���|���vA�^�]=OFF
			mINV11_���|���vB�^�]=OFF
			mINV12_���|���vC�^�]=OFF
			mINV13_���|���vD�^�]=OFF
			mINV14_���|���vE�^�]=OFF
			
			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF

			�}�j���A���|���vstep=0

			tmp���|���v=OFF
			tmp1SV97_�������d����=OFF
			tmp1SV98_�d�グ�d����=OFF
			tmp1INV10_���|���vA�^�]=OFF
			tmp1INV11_���|���vB�^�]=OFF
			tmp1INV12_���|���vC�^�]=OFF
			tmp1INV13_���|���vD�^�]=OFF
			tmp1INV14_���|���vE�^�]=OFF
			
			tmp2SV97_�������d����=OFF
			tmp2SV98_�d�グ�d����=OFF
			tmp2INV10_���|���vA�^�]=OFF
			tmp2INV11_���|���vB�^�]=OFF
			tmp2INV12_���|���vC�^�]=OFF
			tmp2INV13_���|���vD�^�]=OFF
			tmp2INV14_���|���vE�^�]=OFF

			ManualInite=1
		end if
		
		
		if PB45_�S��~SW  and not(manual���R���x�A) then '���R���x�A�����r�o���͂��ׂẴV�����_�������㏸���܂��B
			if ldp(pnlPBSV67_���t�^���������~A) then
				if mSV67_���t�^���������~A then
					mSV67_���t�^���������~A=OFF
				else
					mSV67_���t�^���������~A=ON
				end if
			end if
			
			if ldp(pnlPBSV68_���t�^���������~B) then
				if mSV68_���t�^���������~B then
					mSV68_���t�^���������~B=OFF
				else
					mSV68_���t�^���������~B=ON
				end if
			end if
			
			if ldp(pnlPBSV73_���t�^���������~A) then
				if mSV73_���t�^���������~A then
					mSV73_���t�^���������~A=OFF
				else
					mSV73_���t�^���������~A=ON
				end if
			end if
			
			if ldp(pnlPBSV74_���t�^���������~B) then
				if mSV74_���t�^���������~B then
					mSV74_���t�^���������~B=OFF
				else
					mSV74_���t�^���������~B=ON
				end if
			end if
			
			if ldp(pnlPBSV79_���t�^���������~A) then
				if mSV79_���t�^���������~A then
					mSV79_���t�^���������~A=OFF
				else
					mSV79_���t�^���������~A=ON
				end if
			end if
			
			if ldp(pnlPBSV80_���t�^���������~B) then
				if mSV80_���t�^���������~B then
					mSV80_���t�^���������~B=OFF
				else
					mSV80_���t�^���������~B=ON
				end if
			end if
			
			if ldp(pnlPBSV85_���t�^���������~A) then
				if mSV85_���t�^���������~A then
					mSV85_���t�^���������~A=OFF
				else
					mSV85_���t�^���������~A=ON
				end if
			end if
			
			if ldp(pnlPBSV86_���t�^���������~B) then
				if mSV86_���t�^���������~B then
					mSV86_���t�^���������~B=OFF
				else
					mSV86_���t�^���������~B=ON
				end if
			end if
			
			if ldp(pnlPBSV91_���t�^���������~A) then
				if mSV91_���t�^���������~A then
					mSV91_���t�^���������~A=OFF
				else
					mSV91_���t�^���������~A=ON
				end if
			end if
			
			if ldp(pnlPBSV92_���t�^���������~B) then
				if mSV92_���t�^���������~B then
					mSV92_���t�^���������~B=OFF
				else
					mSV92_���t�^���������~B=ON
				end if
			end if
		else		
			mSV67_���t�^���������~A=OFF
			mSV68_���t�^���������~B=OFF
			mSV73_���t�^���������~A=OFF
			mSV74_���t�^���������~B=OFF
			mSV79_���t�^���������~A=OFF
			mSV80_���t�^���������~B=OFF
			mSV85_���t�^���������~A=OFF
			mSV86_���t�^���������~B=OFF
			mSV91_���t�^���������~A=OFF
			mSV92_���t�^���������~B=OFF
		end if
		
		
		PBL43_���|���v=mINV10_���|���vA�^�] or mINV11_���|���vB�^�] or mINV12_���|���vC�^�] or mINV13_���|���vD�^�] or mINV14_���|���vE�^�]
		mINV10_���|���vA�^�]=(tmp1INV10_���|���vA�^�] or tmp2INV10_���|���vA�^�]) and (FLT2_�^���N���� or not(nottimdly_FLT2_�^���N����.B))
		mINV11_���|���vB�^�]=(tmp1INV11_���|���vB�^�] or tmp2INV11_���|���vB�^�]) and (FLT4_�^���N���� or not(nottimdly_FLT4_�^���N����.B))
		mINV12_���|���vC�^�]=(tmp1INV12_���|���vC�^�] or tmp2INV12_���|���vC�^�]) and (FLT6_�^���N���� or not(nottimdly_FLT6_�^���N����.B))
		mINV13_���|���vD�^�]=(tmp1INV13_���|���vD�^�] or tmp2INV13_���|���vD�^�]) and (FLT8_�^���N���� or not(nottimdly_FLT8_�^���N����.B))
		mINV14_���|���vE�^�]=(tmp1INV14_���|���vE�^�] or tmp2INV14_���|���vE�^�]) and (FLT10_�^���N���� or not(nottimdly_FLT10_�^���N����.B))
		
		mSV97_�������d����=tmp1SV97_�������d���� or tmp2SV97_�������d����
		mSV98_�d�グ�d����=tmp1SV98_�d�グ�d���� or tmp2SV98_�d�グ�d����

		
		
		if PB45_�S��~SW and not(manual���R���x�A) then
			if SEL2_1_�^�]�؊��i�P���j then
				'�R�}���h�X�C�b�`����
			
				'pnlPB�ł̐ݒ�l���N���A
				tmp2SV97_�������d����=OFF
				tmp2SV98_�d�グ�d����=OFF
				tmp2INV10_���|���vA�^�]=OFF
				tmp2INV11_���|���vB�^�]=OFF
				tmp2INV12_���|���vC�^�]=OFF
				tmp2INV13_���|���vD�^�]=OFF
				tmp2INV14_���|���vE�^�]=OFF

				tmp2SV97_�������d����=OFF
				tmp2SV98_�d�グ�d����=OFF
				
				INV10_���|���vA���=OFF
				INV11_���|���vB���=OFF
				INV12_���|���vC���=OFF
				INV13_���|���vD���=OFF
				INV14_���|���vE���=OFF

				'------------------------------------------------------------
				if ldp(PB43_���|���vSW) then
					inc(�}�j���A���|���vstep)
					if �}�j���A���|���vstep>2 then
						�}�j���A���|���vstep=0
					end if
				end if

				if �}�j���A���|���vstep>0 then
					if (FLT2_�^���N���� or not(nottimdly_FLT2_�^���N����.B)) or (FLT4_�^���N���� or not(nottimdly_FLT4_�^���N����.B)) or (FLT6_�^���N���� or not(nottimdly_FLT6_�^���N����.B)) or (FLT8_�^���N���� or not(nottimdly_FLT8_�^���N����.B)) or (FLT10_�^���N���� or not(nottimdly_FLT10_�^���N����.B))  then
						�}�j���A���|���vstep=�}�j���A���|���vstep
					else
						�}�j���A���|���vstep=0
					end if				
				end if

				select case �}�j���A���|���vstep				
				case 0
					tmp���|���v=OFF
					INV10_���|���vA���=OFF
					INV11_���|���vB���=OFF
					INV12_���|���vC���=OFF
					INV13_���|���vD���=OFF
					INV14_���|���vE���=OFF
				case 1
					tmp���|���v=ON
					INV10_���|���vA���=OFF
					INV11_���|���vB���=OFF
					INV12_���|���vC���=OFF
					INV13_���|���vD���=OFF
					INV14_���|���vE���=OFF
				case 2
					tmp���|���v=ON
					INV10_���|���vA���=ON
					INV11_���|���vB���=ON
					INV12_���|���vC���=ON
					INV13_���|���vD���=ON
					INV14_���|���vE���=ON
				end select


				tmp1SV97_�������d����=tmp���|���v
				tmp1SV98_�d�グ�d����=tmp���|���v
				tmp1INV10_���|���vA�^�]=tmp���|���v and (FLT2_�^���N���� or not(nottimdly_FLT2_�^���N����.B)) 
				tmp1INV11_���|���vB�^�]=tmp���|���v and (FLT4_�^���N���� or not(nottimdly_FLT4_�^���N����.B))
				tmp1INV12_���|���vC�^�]=tmp���|���v and (FLT6_�^���N���� or not(nottimdly_FLT6_�^���N����.B))
				tmp1INV13_���|���vD�^�]=tmp���|���v and (FLT8_�^���N���� or not(nottimdly_FLT8_�^���N����.B))
				tmp1INV14_���|���vE�^�]=tmp���|���v and (FLT10_�^���N���� or not(nottimdly_FLT10_�^���N����.B))
				
				
			else
				'�p�l���X�C�b�`����

				'�R�}���hPB�ł̐ݒ�l�N���A
				
				�}�j���A���|���vstep=0
				
				tmp���|���v=OFF
				tmp1SV97_�������d����=OFF
				tmp1SV98_�d�グ�d����=OFF
				tmp1INV10_���|���vA�^�]=OFF
				tmp1INV11_���|���vB�^�]=OFF
				tmp1INV12_���|���vC�^�]=OFF
				tmp1INV13_���|���vD�^�]=OFF
				tmp1INV14_���|���vE�^�]=OFF
				
				tmp1SV97_�������d����=OFF
				tmp1SV98_�d�グ�d����=OFF
				'------------------------------------------------------------
				if ldp(pnlPBINV10_���|���vA�^�])then
					if tmp2INV10_���|���vA�^�] then
						tmp2INV10_���|���vA�^�]=OFF
					else
						tmp2INV10_���|���vA�^�]=ON
					end if
				end if
				tmp2INV10_���|���vA�^�]=tmp2INV10_���|���vA�^�] and FLT2_�^���N����
				'--------------------------------------
				if ldp(pnlPBINV11_���|���vB�^�]) then
					if tmp2INV11_���|���vB�^�] then
						tmp2INV11_���|���vB�^�]=OFF
					else
						tmp2INV11_���|���vB�^�]=ON
					end if
				end if
				tmp2INV11_���|���vB�^�]=tmp2INV11_���|���vB�^�] and FLT4_�^���N����
				'--------------------------------------
				if ldp(pnlPBINV12_���|���vC�^�]) then
					if tmp2INV12_���|���vC�^�] then
						tmp2INV12_���|���vC�^�]=OFF
					else
						tmp2INV12_���|���vC�^�]=ON
					end if
				end if
				tmp2INV12_���|���vC�^�]=tmp2INV12_���|���vC�^�] and FLT6_�^���N����
				'--------------------------------------
				if ldp(pnlPBINV13_���|���vD�^�]) then
					if tmp2INV13_���|���vD�^�] then
						tmp2INV13_���|���vD�^�]=OFF
					else
						tmp2INV13_���|���vD�^�]=ON
					end if
				end if
				tmp2INV13_���|���vD�^�]=tmp2INV13_���|���vD�^�] and FLT8_�^���N����
				'--------------------------------------
				if ldp(pnlPBINV14_���|���vE�^�]) then
					if tmp2INV14_���|���vE�^�] then
						tmp2INV14_���|���vE�^�]=OFF
					else
						tmp2INV14_���|���vE�^�]=ON
					end if
				end if
				tmp2INV14_���|���vE�^�]=tmp2INV14_���|���vE�^�] and FLT10_�^���N����
				'--------------------------------------
				if ldp(pnlPBSV97_�������d����) then
					if tmp2SV97_�������d���� then
						tmp2SV97_�������d����=OFF
					else
						tmp2SV97_�������d����=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBSV98_�d�グ�d����) then
					if tmp2SV98_�d�グ�d���� then
						tmp2SV98_�d�グ�d����=OFF
					else
						tmp2SV98_�d�グ�d����=ON
					end if
				end if					
				'--------------------------------------
				if ldp(pnlPBINV10_���|���vA���) then
					if INV10_���|���vA��� then
						INV10_���|���vA���=OFF
					else
						INV10_���|���vA���=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV11_���|���vB���) then
					if INV11_���|���vB��� then
						INV11_���|���vB���=OFF
					else
						INV11_���|���vB���=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV12_���|���vC���) then
					if INV12_���|���vC��� then
						INV12_���|���vC���=OFF
					else
						INV12_���|���vC���=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV13_���|���vD���) then
					if INV13_���|���vD��� then
						INV13_���|���vD���=OFF
					else
						INV13_���|���vD���=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV14_���|���vE���) then
					if INV14_���|���vE��� then
						INV14_���|���vE���=OFF
					else
						INV14_���|���vE���=ON
					end if
				end if
				'--------------------------------------

			end if	
				
		else
			PBL43_���|���v=OFF
			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF

			mINV10_���|���vA�^�]=OFF
			mINV11_���|���vB�^�]=OFF
			mINV12_���|���vC�^�]=OFF
			mINV13_���|���vD�^�]=OFF
			mINV14_���|���vE�^�]=OFF
			
			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF

			�}�j���A���|���vstep=0
			
			tmp���|���v=OFF
			tmp1SV97_�������d����=OFF
			tmp1SV98_�d�グ�d����=OFF
			tmp1INV10_���|���vA�^�]=OFF
			tmp1INV11_���|���vB�^�]=OFF
			tmp1INV12_���|���vC�^�]=OFF
			tmp1INV13_���|���vD�^�]=OFF
			tmp1INV14_���|���vE�^�]=OFF
			
			tmp2SV97_�������d����=OFF
			tmp2SV98_�d�グ�d����=OFF
			tmp2INV10_���|���vA�^�]=OFF
			tmp2INV11_���|���vB�^�]=OFF
			tmp2INV12_���|���vC�^�]=OFF
			tmp2INV13_���|���vD�^�]=OFF
			tmp2INV14_���|���vE�^�]=OFF

			
		end if

		if not(manual���R���x�A) then
			if ldp(PB25_���@�P���^�]) and (not(PH7_�����m) and not(PH8_�t�^���m)) and (not(PH9_�����m) and not(PH10_�t�^���m)) and  ��򃆃j�b�gOrg  then
				�����T�C�N��flg=ON
				��򊮗�=ON '���R���x�A���� �����҂������邽�߁A�����I�ɐ�򊮗���ON�����Ă����B
				��򃆃j�b�gstep=1
			end if
		end if	
	end if '��򃆃j�b�gAutoMode and not(��򃆃j�b�gOrgErrStep)

	'===================================================================================================================
	'�y ��򃆃j�b�gOrgErr���� �z
	else

		if ResetFlg then
			��򃆃j�b�gOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		��򃆃j�b�gErr=ON
		
		if almXSW82_���t�^���������~�[A or almXSW81_���t�^�������㏸�[A or almXSW84_���t�^���������~�[B or almXSW83_���t�^�������㏸�[B or INV10_���|���vA�ُ� then
			��򃆃j�b�g1Err=ON
		else
			��򃆃j�b�g1Err=OFF
		end if
		if almXSW87_���t�^���������~�[A or almXSW86_���t�^�������㏸�[A or almXSW89_���t�^���������~�[B or almXSW88_���t�^�������㏸�[B or INV11_���|���vB�ُ� then
			��򃆃j�b�g2Err=ON
		else
			��򃆃j�b�g2Err=OFF
		end if
		if almXSW92_���t�^���������~�[A or almXSW91_���t�^�������㏸�[A or almXSW94_���t�^���������~�[B or almXSW93_���t�^�������㏸�[B or INV12_���|���vC�ُ� then
			��򃆃j�b�g3Err=ON
		else
			��򃆃j�b�g3Err=OFF
		end if
		if almXSW97_���t�^���������~�[A or almXSW96_���t�^�������㏸�[A or almXSW99_���t�^���������~�[B or almXSW98_���t�^�������㏸�[B or INV13_���|���vD�ُ� then
			��򃆃j�b�g4Err=ON
		else
			��򃆃j�b�g4Err=OFF
		end if
		if almXSW102_���t�^���������~�[A or almXSW101_���t�^�������㏸�[A or almXSW104_���t�^���������~�[B or almXSW103_���t�^�������㏸�[B or INV14_���|���vE�ُ� then
			��򃆃j�b�g5Err=ON
		else
			��򃆃j�b�g5Err=OFF
		end if

		PBL43_���|���v=OFF

		mINV10_���|���vA�^�]=OFF
		mINV11_���|���vB�^�]=OFF
		mINV12_���|���vC�^�]=OFF
		mINV13_���|���vD�^�]=OFF
		mINV14_���|���vE�^�]=OFF


		mSV97_�������d����=OFF
		mSV98_�d�グ�d����=OFF
		
		INV10_���|���vA���=OFF
		INV11_���|���vB���=OFF
		INV12_���|���vC���=OFF
		INV13_���|���vD���=OFF
		INV14_���|���vE���=OFF

	
		tmr(tim_��򃆃j�b�gErrStep,tim_��򃆃j�b�gErrStep_val)
		
		select case ��򃆃j�b�gErrStep
		case 0

		case 1
			tim_��򃆃j�b�gErrStep_val=20
			res(tim_��򃆃j�b�gErrStep)
			inc(��򃆃j�b�gErrStep)
		
		case 2
			if tim_��򃆃j�b�gErrStep.B then
				inc(��򃆃j�b�gErrStep)
			end if
		
		case 3

			mSV67_���t�^���������~A=OFF
			mSV68_���t�^���������~B=OFF

			mSV73_���t�^���������~A=OFF
			mSV74_���t�^���������~B=OFF
			
			mSV79_���t�^���������~A=OFF
			mSV80_���t�^���������~B=OFF

			mSV85_���t�^���������~A=OFF
			mSV86_���t�^���������~B=OFF

			mSV91_���t�^���������~A=OFF
			mSV92_���t�^���������~B=OFF

		
			inc(��򃆃j�b�gErrStep)
		
		case 4
			if ResetFlg then
				almXSW82_���t�^���������~�[A=OFF 'mSV67_���t�^���������~A
				almXSW81_���t�^�������㏸�[A=OFF
				almXSW84_���t�^���������~�[B=OFF 'mSV68_���t�^���������~B
				almXSW83_���t�^�������㏸�[B=OFF
				
				almXSW87_���t�^���������~�[A=OFF 'mSV73_���t�^���������~A 
				almXSW86_���t�^�������㏸�[A=OFF
				almXSW89_���t�^���������~�[B=OFF 'mSV74_���t�^���������~B
				almXSW88_���t�^�������㏸�[B=OFF
				
				almXSW92_���t�^���������~�[A=OFF 'mSV79_���t�^���������~A
				almXSW91_���t�^�������㏸�[A=OFF
				almXSW94_���t�^���������~�[B=OFF 'mSV80_���t�^���������~B
				almXSW93_���t�^�������㏸�[B=OFF
				
				almXSW97_���t�^���������~�[A=OFF 'mSV85_���t�^���������~A
				almXSW96_���t�^�������㏸�[A=OFF
				almXSW99_���t�^���������~�[B=OFF 'mSV86_���t�^���������~B
				almXSW98_���t�^�������㏸�[B=OFF
				
				almXSW102_���t�^���������~�[A=OFF 'mSV91_���t�^���������~A
				almXSW101_���t�^�������㏸�[A=OFF
				almXSW104_���t�^���������~�[B=OFF 'mSV92_���t�^���������~B
				almXSW103_���t�^�������㏸�[B=OFF
				
		
				if almINV10_���|���vA�ُ� then
					�C���o�[�^10���Z�b�g=ON
				else if	almINV11_���|���vB�ُ� then
					�C���o�[�^11���Z�b�g=ON
				else if almINV12_���|���vC�ُ� then
					�C���o�[�^12���Z�b�g=ON
				else if almINV13_���|���vD�ُ� then
					�C���o�[�^13���Z�b�g=ON
				else if almINV14_���|���vE�ُ� then
					�C���o�[�^14���Z�b�g=ON							
				end if
			
			 	almINV10_���|���vA�ُ�=OFF
			 	almINV11_���|���vB�ُ�=OFF
			 	almINV12_���|���vC�ُ�=OFF
			 	almINV13_���|���vD�ُ�=OFF
			 	almINV14_���|���vE�ُ�=OFF

				inc(��򃆃j�b�gErrStep)
			end if

		
		case 5
			��򃆃j�b�gErr=OFF
			��򃆃j�b�g1Err=OFF
			��򃆃j�b�g2Err=OFF
			��򃆃j�b�g3Err=OFF
			��򃆃j�b�g4Err=OFF
			��򃆃j�b�g5Err=OFF

			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF

			res(tim_XSW82_���t�^���������~�[A)
			res(tim_XSW81_���t�^�������㏸�[A)
			res(tim_XSW84_���t�^���������~�[B)
			res(tim_XSW83_���t�^�������㏸�[B)
			res(tim_XSW87_���t�^���������~�[A)
			res(tim_XSW86_���t�^�������㏸�[A)
			res(tim_XSW89_���t�^���������~�[B)
			res(tim_XSW88_���t�^�������㏸�[B)
			res(tim_XSW92_���t�^���������~�[A)
			res(tim_XSW91_���t�^�������㏸�[A)
			res(tim_XSW94_���t�^���������~�[B)
			res(tim_XSW93_���t�^�������㏸�[B)
			res(tim_XSW97_���t�^���������~�[A)
			res(tim_XSW96_���t�^�������㏸�[A)
			res(tim_XSW99_���t�^���������~�[B)
			res(tim_XSW98_���t�^�������㏸�[B)
			res(tim_XSW102_���t�^���������~�[A)
			res(tim_XSW101_���t�^�������㏸�[A)
			res(tim_XSW104_���t�^���������~�[B)
			res(tim_XSW103_���t�^�������㏸�[B)

			��򃆃j�b�gStep=201
			��򃆃j�b�gErrStep=0
		end select

	end if 'if ��򃆃j�b�gErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else
	select case ��򃆃j�b�gEmgStep
	case 0

	case 1
		��򃆃j�b�gAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		
		if ��򃆃j�b�gstep<>0 or �����T�C�N��flg then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			mINV10_���|���vA�^�]=OFF
			mINV11_���|���vB�^�]=OFF
			mINV12_���|���vC�^�]=OFF
			mINV13_���|���vD�^�]=OFF
			mINV14_���|���vE�^�]=OFF

			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF
			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF

			tmp���|���v=OFF
			tmp1SV97_�������d����=OFF
			tmp1SV98_�d�グ�d����=OFF
			tmp1INV10_���|���vA�^�]=OFF
			tmp1INV11_���|���vB�^�]=OFF
			tmp1INV12_���|���vC�^�]=OFF
			tmp1INV13_���|���vD�^�]=OFF
			tmp1INV14_���|���vE�^�]=OFF
			
			tmp2SV97_�������d����=OFF
			tmp2SV98_�d�グ�d����=OFF
			tmp2INV10_���|���vA�^�]=OFF
			tmp2INV11_���|���vB�^�]=OFF
			tmp2INV12_���|���vC�^�]=OFF
			tmp2INV13_���|���vD�^�]=OFF
			tmp2INV14_���|���vE�^�]=OFF

			if timstack=OFF then
				
				tim_�������t�^�����m_stack.U=tim_�������t�^�����m.U
				tim_procstep_stack.U=tim_procstep.U
				tim_��򃆃j�b�gErrStep_stack.U=tim_��򃆃j�b�gErrStep.U
			' tmr(PH46_�t�^���m or PH45_�����m,tim_�������t�^�����m,20)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_��򃆃j�b�gErrStep,tim_��򃆃j�b�gErrStep_val)

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mINV10_���|���vA�^�]=OFF
			mINV11_���|���vB�^�]=OFF
			mINV12_���|���vC�^�]=OFF
			mINV13_���|���vD�^�]=OFF
			mINV14_���|���vE�^�]=OFF

			mSV97_�������d����=OFF
			mSV98_�d�グ�d����=OFF
			INV10_���|���vA���=OFF
			INV11_���|���vB���=OFF
			INV12_���|���vC���=OFF
			INV13_���|���vD���=OFF
			INV14_���|���vE���=OFF

			tmp���|���v=OFF
			tmp1SV97_�������d����=OFF
			tmp1SV98_�d�グ�d����=OFF
			tmp1INV10_���|���vA�^�]=OFF
			tmp1INV11_���|���vB�^�]=OFF
			tmp1INV12_���|���vC�^�]=OFF
			tmp1INV13_���|���vD�^�]=OFF
			tmp1INV14_���|���vE�^�]=OFF
			
			tmp2SV97_�������d����=OFF
			tmp2SV98_�d�グ�d����=OFF
			tmp2INV10_���|���vA�^�]=OFF
			tmp2INV11_���|���vB�^�]=OFF
			tmp2INV12_���|���vC�^�]=OFF
			tmp2INV13_���|���vD�^�]=OFF
			tmp2INV14_���|���vE�^�]=OFF

			mSV67_���t�^���������~A=OFF
			mSV68_���t�^���������~B=OFF
			mSV73_���t�^���������~A=OFF
			mSV74_���t�^���������~B=OFF
			mSV79_���t�^���������~A=OFF
			mSV80_���t�^���������~B=OFF
			mSV85_���t�^���������~A=OFF
			mSV86_���t�^���������~B=OFF
			mSV91_���t�^���������~A=OFF
			mSV92_���t�^���������~B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(��򃆃j�b�gEmgStep)
	case 2
		if ResetFlg then
			inc(��򃆃j�b�gEmgStep)
		end if
	case 3
		if  ��򃆃j�b�gstep<>0  or �����T�C�N��flg then
			if StartFlg then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------				
				tim_�������t�^�����m.U=tim_�������t�^�����m_stack.U
				tim_procstep.U=tim_procstep_stack.U
				tim_��򃆃j�b�gErrStep.U=tim_��򃆃j�b�gErrStep_stack.U
				' tmr(PH46_�t�^���m or PH45_�����m,tim_�������t�^�����m,20)
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_��򃆃j�b�gErrStep,tim_��򃆃j�b�gErrStep_val)
				
				'---------------------------------
				inc(��򃆃j�b�gEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------

			
			
			'---------------------------------
			inc(��򃆃j�b�gEmgStep)		
		end if				
	case 4
		timstack=OFF
		��򃆃j�b�gEmgStep=0
		��򃆃j�b�gEmg=OFF
	end select
		
end if 'if Emgstep_proc=0 then
