'�����R���x�AF
'===================================================================================================================
'
'<<<<<<<	�R���x�A	>>>>>>>>
'
'===================================================================================================================
'
'	�����R���x�AF 
'
'  	�ړ����x  161.667mm/1sec
'===================================================================================================================
'�y ���������� �z
if CR2008 then '�d��ON������������
    �����R���x�AFAutoMode=ON '��Ɏ�������AutoMode ONLINE�AOFFLINE�Ȃ�
    �����R���x�AFAutoRun=OFF
    �����R���x�AF����=ON
    �����R���x�AFOrgErr=OFF
    �����R���x�AFErr=OFF
    �����R���x�AFEmg=OFF
    �����R���x�AFstep=0
    �����R���x�AFErrStep=0
    �����R���x�AFOrgErrStep=0
    �����R���x�AFEmgStep=0

	MC30_�������[�^step=0
	MC29_�������[�^���]step=0
	MC29_�������[�^�t�]step=0
	MC28_�������[�^���]step=0
	MC28_�������[�^�t�]step=0
	���~���t�g����step=0
	
	ManualInite=1

end if

'===================================================================================================================
'�y ���_ �z
�����R���x�AFOrg=1

'===================================================================================================================
'�y �ً}��~ �z

if not(PB����~) then
	�����R���x�AFEmg=ON
	�����R���x�AFEmgStep=1
end if

'===================================================================================================================
'�y �^�C���G���[���o����ьv���G���[���o�z

tmr(PH36_�����m,timdly_PH36_�����m,4)
tmr(PH37_�t�^���m,timdly_PH37_�t�^���m,4)

tmr(SV55_���t�g and not(XSW68_���t�g�㏸�[) and not(pnlPBXSW68_���t�g�㏸�[),tim_notXSW68_���t�g�㏸�[, #40) '597.04ms
tmr(not(SV55_���t�g) and not(XSW67_���t�g���~�[) and not(pnlPBXSW67_���t�g���~�[),tim_notXSW67_���t�g���~�[, #40) '808.65ms
tmr(SV56_�X�g�b�p and not(XSW70_�X�g�b�p�㏸�[) and not(pnlPBXSW70_�X�g�b�p�㏸�[),tim_notXSW70_�X�g�b�p�㏸�[, #40) '598.55ms
tmr(not(SV56_�X�g�b�p) and not(XSW69_�X�g�b�p���~�[) and not(pnlPBXSW69_�X�g�b�p���~�[),tim_notXSW69_�X�g�b�p���~�[, #40) '851.59ms

'tmr(not(SV55_���t�g) and XSW68_���t�g�㏸�[,tim_XSW68_���t�g�㏸�[, #10) '597.04ms
if LDP(SV55_���t�g) and  XSW68_���t�g�㏸�[ and not(pnlPBXSW68_���t�g�㏸�[) then
	SET(tim_XSW68_���t�g�㏸�[)
end if
'tmr(SV55_���t�g and XSW67_���t�g���~�[,tim_XSW67_���t�g���~�[, #10) '808.65ms
if LDF(SV55_���t�g) and XSW67_���t�g���~�[ and not(pnlPBXSW67_���t�g���~�[) then
	SET(tim_XSW67_���t�g���~�[)
end if
'tmr(not(SV56_�X�g�b�p) and XSW70_�X�g�b�p�㏸�[,tim_XSW70_�X�g�b�p�㏸�[, #10) '598.55ms
if LDP(SV56_�X�g�b�p) and XSW70_�X�g�b�p�㏸�[ and not(pnlPBXSW70_�X�g�b�p�㏸�[) then
	SET(tim_XSW70_�X�g�b�p�㏸�[)
end if
'tmr(SV56_�X�g�b�p and XSW69_�X�g�b�p���~�[,tim_XSW69_�X�g�b�p���~�[, #10) '851.59ms
if LDF(SV56_�X�g�b�p) and XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[) then
	SET(tim_XSW69_�X�g�b�p���~�[)
end if

'passtimXSW68_���t�g�㏸�[_val=#597
tms(SV55_���t�g,passtimXSW68_���t�g�㏸�[, passtimXSW68_���t�g�㏸�[_val) 

'passtimXSW67_���t�g���~�[_val=#808
tms(not(SV55_���t�g),passtimXSW67_���t�g���~�[,passtimXSW67_���t�g���~�[_val)  

'passtimXSW70_�X�g�b�p�㏸�[_val=#598
tms(SV56_�X�g�b�p,passtimXSW70_�X�g�b�p�㏸�[, passtimXSW70_�X�g�b�p�㏸�[_val) 

'passtimXSW69_�X�g�b�p���~�[_val=#851
tms(not(SV56_�X�g�b�p),passtimXSW69_�X�g�b�p���~�[, passtimXSW69_�X�g�b�p���~�[_val) 

tmr(MC28_�������[�^���] and not(pauseMC28_�������[�^���]) and not(EmgMC28_�������[�^���]),timerr_MC28_�������[�^���],#80)
tmr(MC28_�������[�^�t�] and not(pauseMC28_�������[�^�t�]) and not(EmgMC28_�������[�^�t�]),timerr_MC28_�������[�^�t�],#150)
tmr(MC29_�������[�^���] and not(pauseMC29_�������[�^���]) and not(EmgMC29_�������[�^���]),timerr_MC29_�������[�^���],#80)
tmr(MC29_�������[�^�t�] and not(pauseMC29_�������[�^�t�]) and not(EmgMC29_�������[�^�t�]),timerr_MC29_�������[�^�t�],#150)
tmr(ejectMC30_�������[�^ and not(MC30_�������[�^) and not(pauseMC30_�������[�^) and not(EmgMC30_�������[�^),timerr_MC30_�������[�^,#150)


if ldp(timerr_MC28_�������[�^���].B) then
	almMC28_�������[�^���]=ON
	
	mMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	mMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC30_�������[�^=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC29_�������[�^�t�].B) then
	almMC28_�������[�^�t�]=ON
	
	mMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	mMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC30_�������[�^=OFF
	
	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC29_�������[�^���].B) then
	almMC29_�������[�^���]=ON
	
	mMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	mMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC30_�������[�^=OFF

	�R���x�A�ꎞ��~=ON

else if ldp(timerr_MC29_�������[�^�t�].B) then
	almMC29_�������[�^�t�]=ON
	
	mMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	mMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC30_�������[�^=OFF
	
	�R���x�A�ꎞ��~=ON
	
else if ldp(timerr_MC30_�������[�^.B) then
	almMC30_�������[�^=ON
	
	mMC28_�������[�^���]=OFF
	mMC28_�������[�^�t�]=OFF
	mMC29_�������[�^���]=OFF
	mMC29_�������[�^�t�]=OFF
	ejectMC30_�������[�^=OFF

	�R���x�A�ꎞ��~=ON
end if

if (ldp(tim_XSW68_���t�g�㏸�[.B) or ldp(tim_notXSW68_���t�g�㏸�[.B)) and not(pnlPBXSW68_���t�g�㏸�[) then
	pauseSV55_���t�g=ON
	almXSW68_���t�g�㏸�[=ON
	pnlPBXSW68_���t�g�㏸�[=ON
	if tim_XSW68_���t�g�㏸�[ then
		res(tim_XSW68_���t�g�㏸�[)
	end if
	�����R���x�AFErrStep=1

else if (ldp(tim_XSW67_���t�g���~�[.B) or ldp(tim_notXSW67_���t�g���~�[.B)) and not(pnlPBXSW67_���t�g���~�[) then
	almXSW67_���t�g���~�[=ON
	pnlPBXSW67_���t�g���~�[=ON
	if tim_XSW67_���t�g���~�[ then
		res(tim_XSW67_���t�g���~�[)
	end if
	�����R���x�AFErrStep=1

else if (ldp(tim_XSW69_�X�g�b�p���~�[.B) or ldp(tim_notXSW69_�X�g�b�p���~�[.B)) and not(pnlPBXSW69_�X�g�b�p���~�[) then
	almXSW69_�X�g�b�p���~�[=ON
	pnlPBXSW69_�X�g�b�p���~�[=ON
	if tim_XSW69_�X�g�b�p���~�[ then
		res(tim_XSW69_�X�g�b�p���~�[)
	end if
	�����R���x�AFErrStep=1

else if (ldp(tim_XSW70_�X�g�b�p�㏸�[.B) or ldp(tim_notXSW70_�X�g�b�p�㏸�[.B)) and not(pnlPBXSW70_�X�g�b�p�㏸�[) then
	pauseSV56_�X�g�b�p=ON
	almXSW70_�X�g�b�p�㏸�[=ON
	pnlPBXSW70_�X�g�b�p�㏸�[=ON
	if tim_XSW70_�X�g�b�p�㏸�[ then
		res(tim_XSW70_�X�g�b�p�㏸�[)
	end if
	�����R���x�AFErrStep=1
	
end if



'===================================================================================================================
'�y System���� �z
'���̃t���O�̓��[�h�R�}���h�i���������s�j
'System :: �����R���x�AFAutoMode	�������[�h �Z���N�g�X�C�b�`
'System :: �����R���x�AFAutoRun	�p���^�]�\
'System :: �Z��A���j�b�g���� �Y�����j�b�g����\ 
'System :: �����R���x�AFEmg	���̏��~


if �����R���x�AFEmgStep=0 then  
	
	if �����R���x�AFErrStep=0  then
	
	if not(�R���x�A�ꎞ��~) then

	if not(�����R���x�AFOrgErr) then

	if (�����R���x�AFAutoMode and ��������AutoMode ) or �����R���x�AFstep<>0 then
	
		if not(�����R���x�AFAutoMode and ��������AutoMode ) then
			�����R���x�AFAutoRun=OFF
		end if
		
	if ManualInite=1 then
		mSV55_���t�g=ON
		ManualInite=0
	end if

	'===================================================================================================================
	'�y ���t�^�[�^�X�N �z
	'
		tmr(tim_procstep,tim_procstep_val)

		select case �����R���x�AFstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' �I���ҋ@
		'--------------------------------------------------------------------------------------------------------------
		case 1	' ���s
		'--------------------------------------------------------------------------------------------------------------
		' [ �����p���^�] ]
			if �����R���x�AFAutoRun then
				inc(�����R���x�AFstep)
			else 
				�����R���x�AFstep=0 '�I���ҋ@
			end if
				
		case 2
			if PH48_�����m or PH49_�t�^���m then '�ҋ@�ʒu�Ɋ��t�^��������菸�~���t�g�������J��Ԃ�
				�����R���x�AF�r�o�v��=ON
				if not(���]�ق�����������B) then
					inc(�����R���x�AFstep)
				else
					�����R���x�AFstep=1
				end if
				
			else
				inc(�����R���x�AFstep)
			end if			
		
		case 3
			if not(�����R���x�AF���쒆) and not(MC27_���[�^���[��) then
				inc(�����R���x�AFstep)
			else
				�����R���x�AFstep=1
			end if

		case 4
			if �ق����@B�r�o�v�� or �����R���x�AE�r�o�v�� then '�N���g���K
				inc(�����R���x�AFstep)
			else
				�����R���x�AFstep=1
			end if
		
		
		case 5  '���_���o
			if  �����R���x�AFOrg then
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�AFstep)
			else
				�����R���x�AFstep=1
			end if
			
		case 6
				
				�����R���x�AFstep=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100				
			
			if �R���x�AF���r�o�ҋ@ then
			
				if not(PH48_�����m) and not(PH49_�t�^���m) and not(timdly_PH36_�����m.B) and not(timdly_PH37_�t�^���m.B) and  ���]�ق�����������B and �ق����@B�r�o�v�� then '���̎���B����������B���r�o
					'���ق���B���r�o
					
					if �ق����@B���j�b�g���� then
						�����R���x�AFstep=200
					end if
				else
					�����R���x�AFstep=1
				end if
				
			else			
				if not(���]�ق�����������B) and timdly_PH36_�����m.B and timdly_PH37_�t�^���m.B and ((ANDA(StageDevice25,$8000)=$8000) or (PH34_�����m and PH36_�����m)) then '���t�g��̊���B����������B������
				'���ق���B������
					
					�����R���x�AFstep=300
					
				else if not(PH48_�����m) and not(PH49_�t�^���m) and (timdly_PH36_�����m.B or timdly_PH37_�t�^���m.B) then
				'���t�^�A�ق���A���r�o
					
					�����R���x�AFstep=400
				else if not(timdly_PH36_�����m.B) and not(timdly_PH37_�t�^���m.B) then
					�����R���x�AE�r�o�v��=OFF
					�����R���x�AFstep=1
					
				else
					�����R���x�AFstep=1
				end if
			
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 200 '���ق���B���r�o
				�����R���x�AF���쒆=ON
				mSV56_�X�g�b�p=OFF '���~
				mSV55_���t�g=OFF '���~
				inc(�����R���x�AFstep)
			
		case 201
			if (XSW67_���t�g���~�[ and not(pnlPBXSW67_���t�g���~�[)) or passXSW67_���t�g���~�[ then
				if (XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[)) or passXSW69_�X�g�b�p���~�[ then
					inc(�����R���x�AFstep)
				end if
			end if

		case 202
				mMC28_�������[�^�t�]=ON
				mMC29_�������[�^�t�]=ON
				ejectMC30_�������[�^=ON
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�AFstep)
				
		case 203
				if errpass�R���x�A�ꎞ��~ then
					inc(�����R���x�AFstep)
				
				else if not(PH38_�����m) then
					inc(�����R���x�AFstep)
				end if
		
		case 204
				if PH48_�����m or PH49_�t�^���m or errpass�R���x�A�ꎞ��~ then
					mSV55_���t�g=ON
					mSV56_�X�g�b�p=ON
					�R���x�AF���r�o�ҋ@=OFF
					�����R���x�AF���쒆=OFF
					�����R���x�AE�r�o�v��=OFF
					inc(�����R���x�AFstep)
				end if
		
		case 205
				tim_procstep_val=7 '���t�^���o�I���f�B���[
				res(tim_procstep)
				inc(�����R���x�AFstep)
		
		case 206
				if tim_procstep.B then
					inc(�����R���x�AFstep)
				end if				
		
		
		case 207
				mMC28_�������[�^�t�]=OFF
				mMC29_�������[�^�t�]=OFF
				ejectMC30_�������[�^=OFF
				inc(�����R���x�AFstep)
		
		case 208
				tim_procstep_val=0
				res(tim_procstep)
				inc(�����R���x�AFstep)
				
		case 209
				if tim_procstep.B then
					inc(�����R���x�AFstep)
				end if
		
		case 210
				if MC29_�������[�^���]step=0 then 
					�����R���x�AFstep=299
				end if
		case 299
				�R���x�AF���r�o�ҋ@=OFF
				���]�ق�����������B=OFF
				�ق����@B�r�o�v��=OFF				
				�ق����@B���j�b�g����=OFF
				�����R���x�AF���쒆=OFF
				�����R���x�AE�r�o�v��=OFF
				�����R���x�AFstep=1
				
		'--------------------------------------------------------------------------------------------------------------
		case 300 '���ق���B������
				�����R���x�AF���쒆=ON
				mSV55_���t�g=OFF '���~				
				mSV56_�X�g�b�p=OFF '���~
				inc(�����R���x�AFstep)
		
		case 301
			if (XSW67_���t�g���~�[ and not(pnlPBXSW67_���t�g���~�[)) or passXSW67_���t�g���~�[ then 
				inc(�����R���x�AFstep)
			end if

		case 302
			if (XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[)) or passXSW69_�X�g�b�p���~�[ then
				inc(�����R���x�AFstep)
			end if

		case 303
			tim_procstep_val=0
			res(tim_procstep)
			inc(�����R���x�AFstep)
		
		case 304
			if tim_procstep.B then
				inc(�����R���x�AFstep)
			end if			

		case 305
				mMC29_�������[�^���]=ON
				mMC28_�������[�^���]=ON
				
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�AFstep)
				
		case 306
				if errpass�R���x�A�ꎞ��~ then
					inc(�����R���x�AFstep)
				
				else if not(PH36_�����m) and not(PH37_�t�^���m) then
					inc(�����R���x�AFstep)
				end if
		
		case 307
				if PH38_�����m or errpass�R���x�A�ꎞ��~ then
					mSV55_���t�g=ON
					mSV56_�X�g�b�p=ON
					inc(�����R���x�AFstep)
				end if
		
		case 308
				tim_procstep_val=9 '10 '���t�^���o�I���f�B���[
				res(tim_procstep)
				inc(�����R���x�AFstep)
		
		case 309
				if tim_procstep.B then
					mMC29_�������[�^���]=OFF
					mMC28_�������[�^���]=OFF
					inc(�����R���x�AFstep)
				end if
				
		case 310
				�����R���x�AFstep=399

		case 399
				StageDevice26=StageDevice25
				
				���]�ق�����������B=ON
				�����R���x�AF���쒆=OFF
				�����R���x�AE�r�o�v��=OFF
				�����R���x�AFstep=1
		'--------------------------------------------------------------------------------------------------------------
		case 400 '���t�^�A�ق���A���r�o

				�t�^������=not(PH36_�����m) and  PH37_�t�^���m
				
				�����R���x�AF���쒆=ON
				mSV55_���t�g=OFF '���~
				mSV56_�X�g�b�p=OFF '���~
				inc(�����R���x�AFstep)
			
		case 401
				if (XSW67_���t�g���~�[ and not(pnlPBXSW67_���t�g���~�[)) or passXSW67_���t�g���~�[ then
					inc(�����R���x�AFstep)
				end if
		case 402
				if (XSW69_�X�g�b�p���~�[ and not(pnlPBXSW69_�X�g�b�p���~�[)) or passXSW69_�X�g�b�p���~�[ then
					inc(�����R���x�AFstep)
				end if					
		
		case 403
				tim_procstep_val=0
				res(tim_procstep)
				inc(�����R���x�AFstep)
		
		case 404
				if tim_procstep.B then
					inc(�����R���x�AFstep)
				end if			

		case 405		
				mMC29_�������[�^�t�]=ON
				ejectMC30_�������[�^=ON
				errpass�R���x�A�ꎞ��~=OFF
				inc(�����R���x�AFstep)
		
		case 406
				if errpass�R���x�A�ꎞ��~ then
					inc(�����R���x�AFstep)
				
				else if not(PH36_�����m) and not(PH37_�t�^���m) then
					inc(�����R���x�AFstep)
				end if

		case 407
				if not(���]�ق�����������B) then
					if PH48_�����m or PH49_�t�^���m or errpass�R���x�A�ꎞ��~ then
						mSV55_���t�g=ON
						mSV56_�X�g�b�p=ON
						�����R���x�AF���쒆=OFF
						inc(�����R���x�AFstep)
					end if
				else
					inc(�����R���x�AFstep)
				end if

		case 408
				if errpass�R���x�A�ꎞ��~ then
					inc(�����R���x�AFstep)
					
				else if PH48_�����m or PH49_�t�^���m then
					inc(�����R���x�AFstep)
				end if

		case 409
				tim_procstep_val=7 '���t�^���o�I���f�B���[
				res(tim_procstep)
				inc(�����R���x�AFstep)
		
		case 410
				if tim_procstep.B then
					inc(�����R���x�AFstep)
				end if

		case 411
				mMC29_�������[�^�t�]=OFF
				ejectMC30_�������[�^=OFF
				�����R���x�AFstep=499

		case 499
				if �t�^������ and ���]�ق�����������B then
					�R���x�AF���r�o�ҋ@=ON
					�t�^������=OFF
				else
					�R���x�AF���r�o�ҋ@=OFF				
				end if
				
				�����R���x�AF���쒆=OFF
				�����R���x�AE�r�o�v��=OFF
				�����R���x�AFstep=1
		'--------------------------------------------------------------------------------------------------------------
		end select
		
	
	'===================================================================================================================
	'�y �蓮�X�C�b�`�}�j���A������ �z
	'  �}�j���A���X�C�b�`����̓^�C���G���[�𔭐������Ȃ�
	else 
		�����R���x�AFAutoRun=OFF
		
		�����R���x�AFstep=0 '�I��
		
		if ManualInite=0 then
			mSV55_���t�g=OFF
			ManualInite=1
		end if

		res(timerr_MC28_�������[�^���])
		res(timerr_MC28_�������[�^�t�])
		res(timerr_MC29_�������[�^���])
		res(timerr_MC29_�������[�^�t�])
		res(timerr_MC30_�������[�^)
		
		if ldp(pnlPBMC28_�������[�^���])  then
			if not(mMC28_�������[�^�t�]) then
				if mMC28_�������[�^���] then
					mMC28_�������[�^���]=OFF
					mMC28_�������[�^�t�]=OFF
				else
					mMC28_�������[�^���]=ON
					mMC28_�������[�^�t�]=OFF
				end if
			end if
		else if ldp(pnlPBMC28_�������[�^�t�]) then
			if not(mMC28_�������[�^���]) then
				if mMC28_�������[�^�t�] then
					mMC28_�������[�^���]=OFF
					mMC28_�������[�^�t�]=OFF
				else
					mMC28_�������[�^���]=OFF
					mMC28_�������[�^�t�]=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC29_�������[�^���]) then
			if not(mMC29_�������[�^�t�]) then
				if mMC29_�������[�^���] then
					mMC29_�������[�^���]=OFF
					mMC29_�������[�^�t�]=OFF
				else
					mMC29_�������[�^���]=ON
					mMC29_�������[�^�t�]=OFF
				end if
			end if
		else if ldp(pnlPBMC29_�������[�^�t�]) then
			if not(mMC29_�������[�^���]) then
				if mMC29_�������[�^�t�] then
					mMC29_�������[�^���]=OFF
					mMC29_�������[�^�t�]=OFF
				else
					mMC29_�������[�^���]=OFF
					mMC29_�������[�^�t�]=ON
				end if
			end if
		end if
			
	end if '�����R���x�AFAutoMode and not(�����R���x�AFOrgErrStep)

	'===================================================================================================================
	'�y �����R���x�AFOrgErr���� �z
	else

		if ResetFlg then
			�����R���x�AFOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'�y �R���x�A�ꎞ��~���� �z
	else
		res(timerr_MC28_�������[�^���])
		res(timerr_MC28_�������[�^�t�])
		res(timerr_MC29_�������[�^���])
		res(timerr_MC29_�������[�^�t�])
		res(timerr_MC30_�������[�^)
		
		�R���x�A�ꎞ��~��=ON
		alm�a�،x��=ON
		
		if ResetFlg then
			almMC28_�������[�^���]=OFF		
			almMC28_�������[�^�t�]=OFF		
			almMC29_�������[�^���]=OFF
			almMC29_�������[�^�t�]=OFF
			almMC30_�������[�^=OFF
			
			pauseMC29_�������[�^�t�]=OFF
			pauseMC28_�������[�^�t�]=OFF

			�R���x�A�ꎞ��~=OFF
			�R���x�A�ꎞ��~��=OFF
			alm�a�،x��=OFF
			
			errpass�R���x�A�ꎞ��~=ON
			
		end if
		
	end if
	'===================================================================================================================
	'�y �^�C���A�E�g�G���[���� �z
	' �^�C���A�E�g�G���[�́hResetFlg"������A �p���^�]���\
	else

		�����R���x�AFErr=ON

		pauseMC28_�������[�^���]=ON
		pauseMC28_�������[�^�t�]=ON
		pauseMC29_�������[�^���]=ON
		pauseMC29_�������[�^�t�]=ON
		

		select case �����R���x�AFErrStep
		case 0
		case 1
			alm�a�،x��=ON

			if ResetFlg then
				almXSW68_���t�g�㏸�[=OFF
				almXSW67_���t�g���~�[=OFF
				almXSW69_�X�g�b�p���~�[=OFF
				almXSW70_�X�g�b�p�㏸�[=OFF
				
				alm�a�،x��=OFF
				
				inc(�����R���x�AFErrStep)
			end if
		case 2

			res(tim_XSW68_���t�g�㏸�[)
			res(tim_XSW67_���t�g���~�[)
			res(tim_XSW69_�X�g�b�p���~�[)
			res(tim_XSW70_�X�g�b�p�㏸�[)
		
			res(tim_notXSW68_���t�g�㏸�[)
			res(tim_notXSW67_���t�g���~�[)
			res(tim_notXSW69_�X�g�b�p���~�[)
			res(tim_notXSW70_�X�g�b�p�㏸�[)

			pauseMC28_�������[�^���]=OFF
			pauseMC28_�������[�^�t�]=OFF
			pauseMC29_�������[�^���]=OFF
			pauseMC29_�������[�^�t�]=OFF

			pauseSV55_���t�g=OFF
			pauseSV56_�X�g�b�p=OFF

			�����R���x�AFErr=OFF
			�����R���x�AFErrStep=0

		end select

	end if 'if �����R���x�AFErrStep=0 then
	
	'===================================================================================================================
	'�y ����~�����i���̏��~�j �z
else

	select case �����R���x�AFEmgStep
	case 0
	
	case 1
		�����R���x�AFAutoRun=OFF
		'---------------------------------
		'�ً}��~����		
		'---------------------------------
		if (�����R���x�AFAutoMode and ��������AutoMode ) or �����R���x�AFstep<>0 then
			'---------------------------------
			'�ً}��~����(���� �����T�C�N��)		
			'---------------------------------
			EmgMC28_�������[�^���]=ON
			EmgMC28_�������[�^�t�]=ON
			EmgMC29_�������[�^���]=ON
			EmgMC29_�������[�^�t�]=ON
			EmgMC30_�������[�^=ON

			if timstack=OFF then
			
				tim_MC30_�������[�^_stack.U=tim_MC30_�������[�^.U
				tim_MC29_�������[�^���]_stack.U=tim_MC29_�������[�^���].U
				tim_MC29_�������[�^�t�]_stack.U=tim_MC29_�������[�^�t�].U
				tim_MC28_�������[�^���]_stack.U=tim_MC28_�������[�^���].U
				tim_MC28_�������[�^�t�]_stack.U=tim_MC28_�������[�^�t�].U
				tim_���~���t�g����_stack.U=tim_���~���t�g����.U
				tim_procstep_stack.U=tim_procstep.U
				timdly_PH36_�����m_stack.U=timdly_PH36_�����m.U
				timdly_PH37_�t�^���m_stack.U=timdly_PH37_�t�^���m.U
				
			' tmr(tim_MC30_�������[�^,tim_MC30_�������[�^_val)
			' tmr(tim_MC29_�������[�^���],tim_MC29_�������[�^���]_val)
			' tmr(tim_MC29_�������[�^�t�],tim_MC29_�������[�^�t�]_val)
			' tmr(tim_MC28_�������[�^���],tim_MC28_�������[�^���]_val)
			' tmr(tim_MC28_�������[�^�t�],tim_MC28_�������[�^�t�]_val)
			' tmr(tim_���~���t�g����,tim_���~���t�g����_val)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(PH36_�����m,timdly_PH36_�����m,4)
			' tmr(PH37_�t�^���m,timdly_PH37_�t�^���m,4)
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'�ً}��~����(�蓮�j		
			'---------------------------------
			mMC28_�������[�^���]=OFF
			mMC28_�������[�^�t�]=OFF
			mMC29_�������[�^���]=OFF
			mMC29_�������[�^�t�]=OFF
			mMC30_�������[�^=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(�����R���x�AFEmgStep)
	case 2
		if ResetFlg then
			inc(�����R���x�AFEmgStep)
		end if
	case 3
		if (�����R���x�AFAutoMode and ��������AutoMode ) or �����R���x�AFstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'�ً}��~����(����  �����T�C�N��)
				'---------------------------------
				EmgMC28_�������[�^���]=OFF
				EmgMC28_�������[�^�t�]=OFF
				EmgMC29_�������[�^���]=OFF
				EmgMC29_�������[�^�t�]=OFF
				EmgMC30_�������[�^=OFF

				'�X�^�b�N�̒l���^�C�}�[���ݒl�Ƀ��X�g�A
				tim_MC30_�������[�^.U=tim_MC30_�������[�^_stack.U
				tim_MC29_�������[�^���].U=tim_MC29_�������[�^���]_stack.U
				tim_MC29_�������[�^�t�].U=tim_MC29_�������[�^�t�]_stack.U
				tim_MC28_�������[�^���].U=tim_MC28_�������[�^���]_stack.U
				tim_MC28_�������[�^�t�].U=tim_MC28_�������[�^�t�]_stack.U
				tim_���~���t�g����.U=tim_���~���t�g����_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(tim_MC30_�������[�^,tim_MC30_�������[�^_val)
				' tmr(tim_MC29_�������[�^���],tim_MC29_�������[�^���]_val)
				' tmr(tim_MC29_�������[�^�t�],tim_MC29_�������[�^�t�]_val)
				' tmr(tim_MC28_�������[�^���],tim_MC28_�������[�^���]_val)
				' tmr(tim_MC28_�������[�^�t�],tim_MC28_�������[�^�t�]_val)
				' tmr(tim_���~���t�g����,tim_���~���t�g����_val)
				' tmr(tim_procstep,tim_procstep_val)


				'���o�^�C�}�[�̃��Z�b�g
				res(timdly_PH36_�����m)
				res(timdly_PH37_�t�^���m)
				
				' tmr(PH36_�����m,timdly_PH36_�����m,4)
				' tmr(PH37_�t�^���m,timdly_PH37_�t�^���m,4)

				'---------------------------------
				inc(�����R���x�AFEmgStep)
			end if
		else
			'---------------------------------
			'�ً}��~����(�蓮)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(�����R���x�AFEmgStep)		
		end if				
	case 4
		timstack=OFF
		�����R���x�AFEmgStep=0
		�����R���x�AFEmg=OFF
	end select
		
end if 'if �����R���x�AFEmgStep=0 then
