'�A�C�e���t�@�C��
'�A�C�e������CSV�t�@�C���������݁A�ǂݏo�������郂�W��

'�t�@�C���� �A�C�e�����.CSV

'�A�C�e���� 20��
'�A�C�e������ ���p16����         
'�A�C�e���ݒ萅�� 1���[�h�����Ȃ�����  0 ~ 9999
'�A�C�e���������� 1���[�h�����Ȃ�����  0 ~ 9999
'�A�C�e�����l ���p22���� 11����
'------------------------------------------------------------------------------------------
'�y���[�J�����x���z
'ReadFileStep   1���[�h�����Ȃ�����
'WriteFileStep	1���[�h�����Ȃ�����
'loop 1���[�h�����Ȃ�����
'FileErr	�r�b�g[2]
'WriteFileName	������[40]
'WriteStr	������[200]
'ptr�A�C�e������ 2���[�h�����Ȃ�����
'ptr�A�C�e�����l 2���[�h�����Ȃ�����
'------------------------------------------------------------------------------------------
'�A�C�e�����ǂݏo��
'�t�@�C���� �A�C�e�����.csv

'		ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindStart�N����[0])+STR(FindStart�N����[1])+"."+"CSV"
'		initFileread=ON
'		linecnt=0
'		readpar[0]=0  '�ŏ��̍s����Ǎ�
'		readpar[1]=0  '�ŏ��̍s����Ǎ�
'		readpar[2]=50 '�ő�Ǎ�������
'
'		'�N���A
'		for loop=0 to 49 step 1
'			ErrAnalyzeCode[loop]=0
'			ErrAnalyzeCnt[loop]=0
'		next		
'		
'		INC(Filereadstep)
'	
'	case 2
'	
'		if initFileread or readerr[0]) then
'			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
'				inc(linecnt)
'				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el�������[�hstr,el�^�]��str,el�e�X�g�^�]str,el���t��~str,el�O�����^�]��str,el�������[�hstr,el�������[�hstr,el�������[�hstr)
'				if ReadCnt>=7 then
'					'//�i�[����
'				end if
'				if initFileread or readparstak<>readpar[0] then
'					readparstak=readpar[0]
'					initFileread=OFF
'				else
'					inc(Filereadstep)		
'				end if
'				
'			end if
'		end if
'------------------------------------------------------------------------------------------

if ReadFileStep=0 and WriteFileStep=0 and ldp(ItemLoad) then
	linecnt=0
	ReadFileStep=1
else if ReadFileStep=0 and WriteFileStep=0 and ldp(ItemSave) then
	linecnt=0
	WriteFileStep=1
end if



select case ReadFileStep

case 0

case 1
	ReadFileName.T="UserDoc\"+"�A�C�e�����"+"."+"CSV" '�t�@�C����
	initFileread=ON
	linecnt=0
	readpar[0]=0  '�ŏ��̍s����Ǎ�
	readpar[1]=0  '�ŏ��̍s����Ǎ�
	readpar[2]=200 '�ő�Ǎ�������
	inc(ReadFileStep)

case 2
	if 0 then
	for loop=0 to 19 step 1
		ptr�A�C�e������=ptr�A�C�e������+(loop*16)
		*ptr�A�C�e������.T=""
		ptr�A�C�e�����l=ptr�A�C�e�����l+(loop*22)
		*ptr�A�C�e�����l.T=""
		�A�C�e���ݒ萅��[loop+1].U=0
		�A�C�e����������[loop+1].U=0
	next
	end if
	inc(ReadFileStep)

case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)
			ReadCnt=SPLIT(ReadStr.T,",",�A�C�e������str,�A�C�e���ݒ萅��str,�A�C�e����������str,�A�C�e�����lstr)
			if ReadCnt>=4 then
				if linecnt>=2 then
					loop=linecnt-2
					ADRSET(�A�C�e������1,ptr�A�C�e������)
					ADRSET(�A�C�e�����l1,ptr�A�C�e�����l)
					ptr�A�C�e������=ptr�A�C�e������+(loop*16)
					*ptr�A�C�e������.T=�A�C�e������str.T
					ptr�A�C�e�����l=ptr�A�C�e�����l+(loop*22)
					*ptr�A�C�e�����l.T=�A�C�e�����lstr.T
					�A�C�e���ݒ萅��[loop+1].U=RDASC(�A�C�e���ݒ萅��str)
					�A�C�e����������[loop+1].U=RDASC(�A�C�e����������str)
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
	
end select


'------------------------------------------------------------------------------------------
'�A�C�e����񏑂�����
select case WriteFileStep

	case 0
	case 1
		MMKDIR("UserDoc",FileErr)
		INC(WriteFileStep)

	case 2
		if FileErr[0] then '����
			INC(WriteFileStep)
		end if
	
	case 3
		if FileErr[1] then '�ُ�I��
		end if
		INC(WriteFileStep)
	
	case 4
		WriteFileName.T="UserDoc\"+"�A�C�e�����"+"."+"CSV" '�t�@�C����
		MDEL(WriteFileName,FileErr)
		INC(WriteFileStep)
	
	case 5
		if FileErr[0] then '����
			INC(WriteFileStep)
		end if
	
	case 6
		if FileErr[1] then '�ُ�I��
		end if
		INC(WriteFileStep)
	
	case 7 '-->
		
		ADRSET(�A�C�e������1,ptr�A�C�e������)
		ADRSET(�A�C�e�����l1,ptr�A�C�e�����l)
		ptr�A�C�e������=ptr�A�C�e������+(linecnt*16)
		ptr�A�C�e�����l=ptr�A�C�e�����l+(linecnt*22)
		DELETE(WriteStr,200,0)
		WriteStr.T=*ptr�A�C�e������.T+","
		WriteStr.T=WriteStr.T+DASC(�A�C�e���ݒ萅��[linecnt+1].U,1)+","
		WriteStr.T=WriteStr.T+DASC(�A�C�e����������[linecnt+1].U,1)+","
		WriteStr.T=WriteStr.T+*ptr�A�C�e�����l.T
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'�t�@�C��������b
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(WriteFileStep)
	
	case 8
		if FileErr[0] then '����
			INC(WriteFileStep)
		end if
	
	case 9
		if FileErr[1] then '�ُ�I��
		end if
		INC(WriteFileStep)

	case 10
		if linecnt>=19 then
			WriteFileStep=0
		else 
			inc(linecnt)
			WriteFileStep=7
		end if
end select
'------------------------------------------------------------------------------------------
