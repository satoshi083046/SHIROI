'���Y���J�����_�[
'-----------------------------------------------------------------------------------------------------
'�t�@�C���ǂݏo��
'
'	ReadFileName.T="UserDoc\"+"���Y���"+"20"+STR(�J�����_�[�N)+STR(�J�����_�[��)+"."+"CSV" '�t�@�C����
'	
'���Y���t�@�C��������
'
'	WriteFileName.T="UserDoc\"+"���Y���"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" '�t�@�C����
'
'	WriteStatstr="�G���[����"
'	WriteStatstr="���ĊJ�n"
'	WriteStatstr="���Ċ���"
'	WriteStatstr="�z�ĊJ�n"
'	WriteStatstr="�z�ďI��"
'	WriteStatstr="���ъ���"
'
'	'���Y���
'	WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '���t
'	WriteStr.T=WriteStr.T+WriteStatstr+"," '�^�]���
'
'	WriteStepstr="�A�C�e��"+","+EM4001.T+","
'	WriteStepstr=WriteStepstr+"�ݒ萅��"+","+DASC(DM_�ݒ萅�ʊ�l.U,1)+","
'	WriteStepstr=WriteStepstr+"���ʕ␳�l"+","+DASC(DM_���ʕ␳�l,1)+"," '+/- ����
'	WriteStepstr=WriteStepstr+"A�^���N���Đݒ�l" +","+ DASC(DM_A�^���N�ݒ�l.U,1)+","
'	WriteStepstr=WriteStepstr+"A�^���N���Č��ݒl" +","+ DASC(DM_A�^���N���Č��ݒl.U,1)+","
'	WriteStepstr=WriteStepstr+"B�^���N���Đݒ�l" +","+ DASC(DM_B�^���N�ݒ�l.U,1)+","
'	WriteStepstr=WriteStepstr+"B�^���N���Č��ݒl" +","+ DASC(DM_B�^���N���Č��ݒl.U,1)+","
'	WriteStepstr=WriteStepstr+"�z�đ���"+","+DASC(DM_�z�đ���.U,1)+","
'	WriteStepstr=WriteStepstr+"���]��"+","+DASC(DM_�r�o����.U,1)
'	WriteStr.T=WriteStr.T+CHR($0D) 

'	1		2023/8/12 12:11    
'	2		�G���[����,���ĊJ�n,���Ċ���,�z�ĊJ�n,�z�ďI��,���ъ���
'	3,4		�A�C�e��,EM4001.T,
'	5,6		�z�đ���,DM_�z�đ���.U,
'	7,8		�ݒ萅��,DM_�ݒ萅�ʊ�l.U,
'	9,10	���ʕ␳�l,DM_���ʕ␳�l
'	11,12	A�^���N���Đݒ�l,DM_A�^���N�ݒ�l.U
'	13,14	A�^���N���Č��ݒl,DM_A�^���N���Č��ݒl.U
'	15,16	B�^���N���Đݒ�l,DM_B�^���N�ݒ�l.U
'	17,18	B�^���N���Č��ݒl,DM_B�^���N���Č��ݒl.U
'	19,20	���]��,DM_�r�o����.U
'
'	ReadStr
'	1		strReadDATE
'	2		strReadStat
'	3,4		strReadLABEL1,strRead�A�C�e��,
'	5,6		strReadLABEL2,strRead�z�đ���,
'	7,8		strReadLABEL3,strRead�ݒ萅��,
'	9,10	strReadLABEL4,strRead���ʕ␳�l,
'	11,12	strReadLABEL5,strReadA�^���N���Đݒ�l,
'	13,14	strReadLABEL6,strReadA�^���N���Č��ݒl,
'	15,16	strReadLABEL7,strReadB�^���N���Đݒ�l,
'	17,18	strReadLABEL8,strReadB�^���N���Č��ݒl,
'	19,20	strReadLABEL9,strRead���]��
'
'ReadStr.T="1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20"
'ReadCnt=SPLIT(ReadStr,",",strReadDATE,strReadStat,strReadLABEL1,strRead�A�C�e��,strReadLABEL2,strRead�z�đ���,strReadLABEL3,strRead�ݒ萅��,strReadLABEL4,strTemp1)

'-----------------------------------------------------------------------------------------------------
if ���C��TP_�\�����y�[�WNo=213 or �T�uTP_�\�����y�[�WNo=213 or �ނ炵TP_�\�����y�[�WNo=213 then

	
	if init=OFF then
		init=ON
		'--------------------------------------------------------------
		'�\���o�b�t�@�̃N���A
		for loop=0 to 36 step 1
			ADRSET(���Y�A�C�e��1,ptr���Y�A�C�e��) '���Y�A�C�e��
			ADRADD(loop*16,ptr���Y�A�C�e��)
			*ptr���Y�A�C�e��=0
			���Y����[loop]=RDASC(strRead�z�đ���)
			���Y�ݒ萅��[loop]=RDASC(strRead�ݒ萅��)
		next
		�A�C�e���\����BIT0.U=0
		�A�C�e���\����BIT1.U=0
		�A�C�e���\����BIT2.U=0
		�A�C�e���\����BIT3.U=0
		'--------------------------------------------------------------
		�J�����_�[�N = 2000 + CM700
		�J�����_�[�� = CM701
		dsp�X�V=ON
	end if

	if dsp�X�V=OFF and  ReadFileStep=0 and ItemReadFileStep=0 then	
		if ldp(pnlPBel���ړ�) then
			if �J�����_�[��>1 then
				dec(�J�����_�[��)
				dsp�X�V=ON
			else if �J�����_�[�N>2023 then
				dec(�J�����_�[�N)
				�J�����_�[��=12
				dsp�X�V=ON
			else
				�J�����_�[��=1			
			end if
		else if ldp(pnlPBel�E�ړ�) then
			if �J�����_�[��<12 then
				inc(�J�����_�[��)
				dsp�X�V=ON
			else if �J�����_�[�N<2050 then
				inc(�J�����_�[�N)
				�J�����_�[��=1
				dsp�X�V=ON
			else
				�J�����_�[��=12			
			end if
		end if
	end if
	
	if ldp(dsp�X�V) then
	
		�J�����_�[�N�� = STR(�J�����_�[�N) +"/"+STR(�J�����_�[��)+"/1"
		�J�����_�[�j��=0
		�J�����_�[����=0
		for loop=0 to 39 step 1
			�J�����_�[���t[loop]=0
		next
		for loop=0 to 3 step 1
			�J�����_�[�\����[loop]=0
		next

		'-------------------------------------------------------
		'�j�����x��.csv �Q��
		RES(readwaittim)
		ReadFileStep=1

		dsp�X�V=0
		
	end if

else
	init=OFF
end if

'--------------------------------------------------------------
if ReadFileStep>0 or ItemReadFileStep>0 then
	FileLoading�\��=ON
else
	FileLoading�\��=OFF
end if
'------------------------------------------------------------------------------------------'-----------------------------------------------------------------------------------------------------
select case ReadFileStep

case 0

case 1
	if readwaittim then
		inc(ReadFileStep)
	end if

case 2
	'--------------------------------------------------------------
	'�\���o�b�t�@�̃N���A
	for loop=0 to 36 step 1
		ADRSET(���Y�A�C�e��1.T,ptr���Y�A�C�e��) '���Y�A�C�e��
		ADRADD(loop*16,ptr���Y�A�C�e��)
		*ptr���Y�A�C�e��=0
		���Y����[loop]=RDASC(strRead�z�đ���)
		���Y�ݒ萅��[loop]=RDASC(strRead�ݒ萅��)
	next
	�A�C�e���\����BIT0.U=0
	�A�C�e���\����BIT1.U=0
	�A�C�e���\����BIT2.U=0
	�A�C�e���\����BIT3.U=0
	'--------------------------------------------------------------

	ReadFileName.T="�j�����x��.csv" '�t�@�C���� �j�����x��.csv
	initFileread=ON
	linecnt=0
	readpar[0]=0  '�ŏ��̍s����Ǎ�
	readpar[1]=0  '�ŏ��̍s����Ǎ�
	readpar[2]=200 '�ő�Ǎ�������
	inc(ReadFileStep)

case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)
			ReadCnt=SPLIT(ReadStr.T,",",tmp���t,tmp�j��,tmp����)
			
			if ReadCnt>=3 then
				if linecnt>=2 then
					loop=linecnt-2
						if tmp���t.T=�J�����_�[�N��.T then
							�J�����_�[�j��=RDASC(tmp�j��)
							�J�����_�[����=RDASC(tmp����)
							days=0
							for loop=0 to �J�����_�[����-1 step 1
								inc(days)
								�J�����_�[���t[�J�����_�[�j��+loop]=days
							next
							'--------------------------------------------
							�J�����_�[�\����[0]=$FFFF
							�J�����_�[�\����[1]=$FFFF
							�J�����_�[�\����[2]=$1F
							'--------------------------------------------
							if �J�����_�[���t[0]=0 then
								EM3300.00=OFF
							end if
							if �J�����_�[���t[1]=0 then
								EM3300.01=OFF
							end if
							if �J�����_�[���t[2]=0 then
								EM3300.02=OFF
							end if
							if �J�����_�[���t[3]=0 then
								EM3300.03=OFF
							end if
							if �J�����_�[���t[4]=0 then
								EM3300.04=OFF
							end if
							if �J�����_�[���t[5]=0 then
								EM3300.05=OFF
							end if
							if �J�����_�[���t[6]=0 then
								EM3300.06=OFF
							end if							
							'--------------------------------------------
							if �J�����_�[���t[28]=0 then
								EM3301.12=OFF
							end if
							if �J�����_�[���t[29]=0 then
								EM3301.13=OFF
							end if
							if �J�����_�[���t[30]=0 then
								EM3301.14=OFF
							end if
							if �J�����_�[���t[31]=0 then
								EM3301.15=OFF
							end if
							if �J�����_�[���t[32]=0 then
								EM3302.00=OFF
							end if
							if �J�����_�[���t[33]=0 then
								EM3302.01=OFF
							end if
							if �J�����_�[���t[34]=0 then
								EM3302.02=OFF
							end if
							'--------------------------------------------
							if �J�����_�[���t[35]=0 then
								EM3302.03=OFF
							end if
							if �J�����_�[���t[36]=0 then
								EM3302.04=OFF
							end if
							'--------------------------------------------
						end if
				end if 
			end if

			
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					inc(ReadFileStep)
				end if
		end if
	end if

case 4
	ReadFileStep=0
	
	'�A�C�e�����t�@�C���Ǎ�
	RES(readwaittim)
	ItemReadFileStep=1
	
end select


'-----------------------------------------------------------------------------------------------------------------------------
'���Y���t�@�C���Ǎ�
'-----------------------------------------------
'�J�����_�[�ւ̓��t������
'�j�����x��.csv����y/m/1���������Đ擪�̗j���ƌ��̓������擾���A�J�����_�[���t�ƃJ�����_�[�\�����̃r�b�g�Z�b�g������B
'	�J�����_�[�N		1���[�h�����Ȃ�����	EM3200		��������N
'	�J�����_�[��		1���[�h�����Ȃ�����	EM3201		�������錎
'	�J�����_�[�N��		������[16]	EM3202				��������N���̐擪2023/2/1
'	�J�����_�[�j��		1���[�h�����Ȃ�����	EM3222		��������N���̐擪1���̗j���i���j=0)
'	�J�����_�[����		1���[�h�����Ȃ�����	EM3223		��������N���̓���
'	�J�����_�[���t		1���[�h�����Ȃ�����[40]	EM3240	�Z���ɕ\��������ɂ�(1~31)
'	�J�����_�[�\����	�r�b�g[40]	EM3300				�Z���ɕ\���E��\���ݒ� 1=�\��
'LOCAL	
'	���ѓ�				�t�@�C���ɋL�����ꂽ���ѓ� ��  2023/8/12 8:23   -> 12 				
'	dspSEL =�J�����_�[�j��+���ѓ�  �P���̃Z���{�t�@�C���ɋL�����ꂽ���ѓ�
'-----------------------------------------------
'�J�����_�[�ւ̕\������
'	���Y�A�C�e��1~40	������[16]
'	���Y�ݒ萅��		1���[�h�����Ȃ�����[40]
'	���Y����			1���[�h�����Ȃ�����[40]

'--------------------------------------------------------
'dspSEL =�J�����_�[�j��+���ѓ�	�o�^����Z���̃A�h���X
'--------------------------------------------------------
'[���ѓ��̒��o]
'teststring="2023/9/11 9:22"

'ReadCnt=SPLIT(teststring,"/",tmpY,tmpM,tmpD)
'ReadCnt=SPLIT(tmpD," ",tmpDAY,tmpTIME)
'���ѓ�=RDASC(tmpDAY)
'--------------------------------------------------------
'[�J�����_�[�Z���ւ̃A�C�e���o�^]
'strRead�A�C�e��.T=""

'ADRSET(���Y�A�C�e��1.T,ptr���Y�A�C�e��) '���Y�A�C�e��
'ADRADD((dspSEL)*16,ptr���Y�A�C�e��)
'*ptr���Y�A�C�e��.T=""
'*ptr���Y�A�C�e��.T=strRead�A�C�e��.
'���Y����[dspSEL]=RDASC(strRead�z�đ���)
'���Y�ݒ萅��[dspSEL]=RDASC(strRead�ݒ萅��)
'--------------------------------------------------------


TMR(readwaittim,#5)

'--------------------------------------------------------
select case ItemReadFileStep

case 0


case 1
	if readwaittim.B then
		inc(ItemReadFileStep)
	end if

case 2

	'--------------------------------------------------------------
	'�\���o�b�t�@�̃N���A
	for loop=0 to 36 step 1
		ADRSET(���Y�A�C�e��1,ptr���Y�A�C�e��) '���Y�A�C�e��
		ADRADD(loop*16,ptr���Y�A�C�e��)
		*ptr���Y�A�C�e��=0
		���Y����[loop]=RDASC(strRead�z�đ���)
		���Y�ݒ萅��[loop]=RDASC(strRead�ݒ萅��)
	next
	�A�C�e���\����BIT0.U=0
	�A�C�e���\����BIT1.U=0
	�A�C�e���\����BIT2.U=0
	�A�C�e���\����BIT3.U=0	
	'--------------------------------------------------------------
	ReadFileName.T="UserDoc\"+"���Y���"+STR(�J�����_�[�N)+STR(�J�����_�[��)+"."+"CSV" '�t�@�C����
	initFileread=ON
	linecnt=0
	readpar[0]=0  '�ŏ��̍s����Ǎ�
	readpar[1]=0  '�ŏ��̍s����Ǎ�
	readpar[2]=200 '�ő�Ǎ�������
	'--------------------------------------------------------------
	inc(ItemReadFileStep)
	
case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)

			ReadCnt=SPLIT(ReadStr,",",strReadDATE,strReadStat,strReadLABEL1,strRead�A�C�e��,strReadLABEL2,strRead�z�đ���,strReadLABEL3,strRead�ݒ萅��,strReadLABEL4,strTemp1)
			
			if ReadCnt>=10 then
				if linecnt>=2 then
					loop=linecnt-2 '�ǂݍ��񂾍s���̉��s��
						if strReadStat="���ъ���" then
							ReadCnt=SPLIT(strReadDATE,"/",tmpY,tmpM,tmpD)
							ReadCnt=SPLIT(tmpD," ",tmpDAY,tmpTIME)
							���ѓ�=RDASC(tmpDAY)
							
							dspSEL =�J�����_�[�j��+���ѓ�-1
							ADRSET(���Y�A�C�e��1.T,ptr���Y�A�C�e��) '���Y�A�C�e��
							ADRADD(dspSEL*16,ptr���Y�A�C�e��)
							*ptr���Y�A�C�e��.T=strRead�A�C�e��.T
							���Y����[dspSEL]=RDASC(strRead�z�đ���)
							���Y�ݒ萅��[dspSEL]=RDASC(strRead�ݒ萅��)
							�A�C�e���\����BIT0:dspSEL=ON
						end if
				end if 
			end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					inc(ItemReadFileStep)
				end if
		end if
	end if

case 4
	ItemReadFileStep=0
	
end select

'--------------------------------------------------------
