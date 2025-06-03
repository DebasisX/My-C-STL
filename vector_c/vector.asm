section .text
; the functions
global asm_insint, asm_insd, asm_insstr
global asm_deli, asm_deld, asm_dels
global asm_srchi, asm_srchd, asm_srchs
global asm_idxi, asm_idxd, asm_idxs

; basic insertion rdi=vector, rsi=value
asm_insint:
    mov     rax, [rdi]          ; data pointer
    mov     rcx, [rdi + 8]      ; sz
    mov     edx, [rsi]          ; value to insert
    mov     [rax + rcx*4], edx  ; store at data[sz]
    ret

asm_insd:  ; movsd bcoz, sse update to simd instruction set.
    mov     rax, [rdi]          
    mov     rcx, [rdi + 8]      
    movsd   xmm0, [rsi] ; (128 bit) for floating pt. operations, we use xmm0 register         
    movsd   [rax + rcx*8], xmm0 ; 8 as it is double
    ret

asm_insstr:
    mov     rax, [rdi]          
    mov     rcx, [rdi + 8]      
    mov     rdx, [rsi]          
    mov     [rax + rcx*8], rdx  
    ret

asm_deli:
    mov     r8, [rdi]           
    mov     r9, [rdi + 8]       
    lea     r10, [r9 - 1]       
    
    ; source and destination
    lea     rdx, [r8 + rsi*4 + 4]  ; src = &data[index+1]
    lea     rax, [r8 + rsi*4]      ; dst = &data[index]
    
    ; bytes to move	
    mov     rcx, r10
    sub     rcx, rsi              ; count = sz - index - 1
    shl     rcx, 2                ; bytes = count * 4
    
    rep movsb  ; to move rcx bytes from [rdx] to [rax]
    ret
asm_deld:
    mov     r8, [rdi]        
    mov     r9, [rdi + 8]    
    lea     r10, [r9 - 1]    
    
    lea     rdx, [r8 + rsi*8 + 8]  
    lea     rax, [r8 + rsi*8]      
    mov     rcx, r10
    sub     rcx, rsi              
    shl     rcx, 3                    
    rep movsb
    ret
asm_dels:
    mov     r8, [rdi]           
    mov     r9, [rdi + 8]       
    lea     r10, [r9 - 1]       
    
    lea     rdx, [r8 + rsi*8 + 8]  
    lea     rax, [r8 + rsi*8]      
    
    mov     rcx, r10
    sub     rcx, rsi              
    shl     rcx, 3                
    rep movsb
    ret

asm_srchi:
    mov     rax, [rdi]          
    mov     rcx, [rdi + 8]      
    mov     edx, [rsi]          ; target value
    xor     r8, r8              ; index = 0
.srchloopi:
    cmp     r8, rcx
    jge     .notfoundi
    cmp     [rax + r8*4], edx
    je      .foundi
    inc     r8
    jmp     .srchloopi

asm_srchd:
    mov     rax, [rdi]          
    mov     rcx, [rdi + 8]      
    movsd   xmm1, [rsi]         
    xor     r8, r8              

.srchloopd:
    cmp     r8, rcx
    jge     .notfoundd
    movsd   xmm0, [rax + r8*8]
    ucomisd xmm0, xmm1 ; compare 2 xmm double precision fp vals, from cheatsheet
    jp      .next_d              ; case: NaN
    je      .foundd
.next_d:
    inc     r8
    jmp     .srchloopd ; final
.foundd:
    mov     rax, r8
    ret

.notfoundd:
    mov     rax, -1
    ret

asm_srchs:
    mov     rax, [rdi]          
    mov     rcx, [rdi + 8]      
    mov     rdx, [rsi]          
    xor     r8, r8              
.srchloops:
    cmp     r8, rcx
    jge     .notfounds
    mov     r9, [rax + r8*8]
    cmp     r9, rdx
    je      .founds
    inc     r8
    jmp     .srchloops

; esi=index, rdx=out
asm_idxi:
    mov     rax, [rdi]          
    mov     ecx, [rax + rsi*4]
    mov     [rdx], ecx
    ret

asm_idxd:
    mov     rax, [rdi]          
    movsd   xmm0, [rax + rsi*8]
    movsd   [rdx], xmm0
    ret
asm_idxs:
    mov     rax, [rdi]          
    mov     rcx, [rax + rsi*8]
    mov     [rdx], rcx
    ret

.foundi:
    mov     rax, r8
    ret
.notfoundi:
    mov     rax, -1
    ret

.founds:
    mov     rax, r8
    ret
.notfounds:
    mov     rax, -1
    ret
