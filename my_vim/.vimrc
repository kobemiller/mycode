"-------------------------------------------------------------------
" 	VIM 配置
"
"	最后修改时间：2014-08-10
"-------------------------------------------------------------------

" vundle 配置
set nocompatible
filetype off
set rtp+=~/.vim/bundle/Vundle
call vundle#begin()

Plugin 'gmarik/Vundle'

Plugin 'tpope/vim-fugitive'
Plugin 'spf13/vim-colors'
Plugin 'Lokaltog/vim-powerline'
Plugin 'WolfgangMehner/vim-plugins'

" python
Plugin 'SirVer/ultisnips'
Plugin 'honza/vim-snippets'
Bundle 'klen/python-mode'
Bundle 'python.vim'
Bundle 'python_match.vim'
Bundle 'pythoncomplete'

Plugin 'clang-complete'
Plugin 'supertab'
Plugin 'ku-quickfix'
Plugin 'echofunc.vim'
Plugin 'a.vim'
Plugin 'minibufexpl.vim'
Plugin 'mru.vim'
Plugin 'winmanager'
Plugin 'taglist.vim'
Plugin 'tagexplorer.vim'

call vundle#end()

filetype plugin indent on
syntax on                        " 使用语法高亮
set autoread                     " 正在编辑文件被其他程序改动时自动重新加载
set nocp                         " 使用不兼容 vi 的模式

set autoindent       		 " 设置自动对齐(缩进)
set smartindent               	 " 智能对齐方式
set wrap 			 " 自动换行
set linebreak 			 " 整词换行

set cindent              	 " 使用 C/C++ 语言的自动缩进方式
set backspace=2          	 " 设置退格键可用
set mouse=a              	 " 使用鼠标
set number              	 " 显示行号
"set cul                          " 显示当前行下划线

set shiftwidth=4
set tabstop=4                    " 设置制表符(tab键)的宽度
"set softtabstop=8                " 设置软制表符的宽度
set expandtab			 " Tab替换空格
set smarttab

scriptencoding utf-8             " 设置编码

"set cursorline                   " 高亮当前行

highlight clear SignColumn
highlight clear LineNr

colorscheme ron                  " 设置配色方案

if filereadable(expand("~/.vim/colors/solarized.vim"))
        let g:solarized_termcolors=256
        let g:solarized_termtrans=1
        let g:solarized_contrast="normal"
        let g:solarized_visibility="normal"
        "color solarized
endif

" 自动补全列表的颜色设置
highlight Pmenu ctermfg=black 
highlight PmenuSel ctermfg=white ctermbg=black

" clang_complete 自动补全插件设置
set completeopt=longest,menu
let g:clang_complete_copen=0
let g:clang_auto_select=1
let g:clang_complete_auto=1
let g:clang_complete_macros=1
let g:clang_use_library=1
let g:clang_user_options="-std=c++11"

" 设置超级TAB的补全
let g:SuperTabRetainCompletionType=0
let g:SuperTabDefaultCompletionType="<C-X><C-U>"

" UltiSnips(python 自动补全)
let g:UltiSnipsExpandTrigger="<c-j>"
let g:UltiSnipsJumpForwardTrigger="<c-b>"
let g:UltiSnipsJumpBackwardTrigger="<c-z>"

" Pymode
let g:pymode_lint_checkers = ['pyflakes']
let g:pymode_trim_whitespaces = 0
let g:pymode_options = 0
let g:pymode_rope = 0

autocmd FileType python setlocal omnifunc=pythoncomplete#Complete

" MiniBufferExplorer 的设置
let g:miniBufExplMapWindowNavVim=1 		" 按下Ctrl+h/j/k/l，可以切换到当前窗口的上下左右窗口
let g:miniBufExplMapWindowNavArrows=1 		" 按下Ctrl+箭头，可以切换到当前窗口的上下左右窗口
let g:miniBufExplMapCTabSwitchBufs=1 		" Ctrl+tab移到下一个窗口；Ctrl+Shift+tab移到上一个窗口
let g:miniBufExplModSelTarget=1    		" 不要在不可编辑内容的窗口（如TagList窗口）中打开选中的buffer

" 设置分屏浏览
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<CR>

" 符号配对
function ClosePair(char)
	if getline('.')[col('.') - 1] == a:char
 		return "\<Right>"
 	elseif (a:char == "\'" || a:char == "\"")
 		return a:char.a:char."\<left>"
 	else
 		return a:char
	endif
endf

" 设置键映射
inoremap { {}<ESC>i
inoremap } <c-r>=ClosePair('}')<CR>
inoremap [ []<ESC>i
inoremap ] <c-r>=ClosePair(']')<CR>

" 显示历史打开文件
map <F3> :MRU<CR>
imap <F3> <ESC>:MRU<CR>

" F4 切换粘贴和非粘贴模式
set pastetoggle=<F4>

" ctags 相关设置

" 按下F5，在当前目录递归生成tag文件
map <F5> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q<CR><CR>
imap <F5> <ESC>:!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q<CR><CR>

" vim 启动时自动载入以下tags文件
"set tags=tags
"set tags+=./tags
set tags=./tags,tags;$HOME

"set tags+=/usr/local/src/linux-2.6.32.61/tags
"set tags+=/usr/local/src/linux-3.12.6/tags
set tags+=/usr/include/arpa/tags
set tags+=/usr/include/bits/tags
set tags+=/usr/include/boost/tags
set tags+=/usr/include/c++/tags
set tags+=/usr/include/curl/tags
set tags+=/usr/include/gnu/tags
set tags+=/usr/include/gtest/tags
set tags+=/usr/include/linux/tags
set tags+=/usr/include/libmemcached/tags
set tags+=/usr/include/mysql/tags
set tags+=/usr/include/net/tags
set tags+=/usr/include/netinet/tags
set tags+=/usr/include/openssl/tags
set tags+=/usr/include/sasl/tags
set tags+=/usr/include/sys/tags

"cscope 相关设置
if has("cscope")
    set cscopetag   " 使支持用 Ctrl+]  和 Ctrl+t 快捷键在代码间跳来跳去
    " check cscope for definition of a symbol before checking ctags:
    " set to 1 if you want the reverse search order.
    set csto=1

    " add any cscope database in current directory
    if filereadable("cscope.out")
        cs add cscope.out
        " else add the database pointed to by environment variable
    elseif $CSCOPE_DB !=""
        cs add $CSCOPE_DB
    endif

    " show msg when any other cscope db added
    set cscopeverbose

    nmap <C-/>s :cs find s <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/>g :cs find g <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/>c :cs find c <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/>t :cs find t <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/>e :cs find e <C-R>=expand("<cword>")<CR><CR>
    nmap <C-/>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
    nmap <C-/>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
    nmap <C-/>d :cs find d <C-R>=expand("<cword>")<CR><CR>
endif

" 系统剪贴板映射 
set clipboard=unnamedplus
map <C-y> "+y
map <C-p> "+p

" QuickFix 插件的设置

" 按下F6，执行make编译程序，并打开quickfix窗口，显示编译信息
map <F6> :make<CR><CR><CR> :copen<CR><CR>
" 按下F7，光标移到上一个错误所在的行
map <F7> :cp<CR>
" 按下F8，光标移到下一个错误所在的行
map <F8> :cn<CR>
" 按下F9，执行make clean
map <F9> :make clean<CR><CR><CR>

" 以下的映射是使上面的快捷键在插入模式下也能用
imap <F6> <ESC>:make clean<CR><CR><CR>
imap <F7> <ESC>:make<CR><CR><CR> :copen<CR><CR>
imap <F8> <ESC>:cp<CR>
imap <F9> <ESC>:cn<CR>

" 按下F10，在当前代码的 .c / .h 之间切换
nnoremap <silent> <F10> :A<CR>

" powerline 配置
set nocompatible
set laststatus=2
set encoding=utf-8
set t_Co=256
set guifont=PowerlineSymbols\ for\ Powerline 
let g:Powerline_symbols='unicode'

" 预防手误
cnoremap Q! q!
cnoremap Q1 q!
command  Q  q
command  Wq wq
command  WQ wq
command  W  w

" 查字典
function! Mydict()
        let expl=system('sdcv -n ' . expand("<cword>"))
        windo if expand("%")=="dict-tmp" |q!|endif	
        30vsp dict-tmp
        setlocal buftype=nofile bufhidden=hide noswapfile
        1s/^/\=expl/
        wincmd p
endf

"按键绑定，将调用函数并执行
map f :call Mydict()<CR><C-j><C-l>
