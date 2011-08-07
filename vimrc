" An example for a vimrc file.
"
" Maintainer:	Bram Moolenaar <Bram@vim.org>
" Last change:	2002 May 28
"
" To use it, copy it to
"     for Unix and OS/2:  ~/.vimrc
"	      for Amiga:  s:.vimrc
"  for MS-DOS and Win32:  $VIM\_vimrc
"	    for OpenVMS:  sys$login:.vimrc

" When started as 
"evim", evim.vim will already have done these settings.
if v:progname =~? "evim"
  finish

endif

" Use Vim settings, rather then Vi settings (much better!).
" This must be first, because it changes other options as a side effect.
set scrolloff=100
set nocompatible
set cursorline
" allow backspacing over everything in insert mode
set backspace=indent,eol,start
set background=dark
set autoindent		" always set autoindenting on
set backup		" keep a backup file
set backupdir=~/bkp/vim
set history=50		" keep 50 lines of command line history
set ruler		" show the cursor position all the time
set showcmd		" display incomplete commands
set incsearch		" do incremental searching
set smartcase           " do search smartly
" For Win32 GUI: remove 't' flag from 'guioptions': no tearoff menu entries
" let &guioptions = substitute(&guioptions, "t", "", "g")

" Don't use Ex mode, use Q for formatting
"map Q gq

" This is an alternative that also works in block mode, but the deleted
" text is lost and it only works for putting the current register.
"vnoremap p "_dp

" Switch syntax highlighting on, when the terminal has colors
" Also switch on highlighting the last used search pattern.
if &t_Co > 2 || has("gui_running")
  syntax on
  set hlsearch
endif

" Only do this part when compiled with support for autocommands.
"
if has("autocmd")

" autocmd FileType python set complete+=k/path/to/pydiction isk+=.,(
  " Enable file type detection.
  " Use the default filetype settings, so that mail gets 'tw' set to 72,
  " 'cindent' is on in C files, etc.
  " Also load indent files, to automatically do language-dependent indenting.
  filetype plugin indent on

  " Put these in an autocmd group, so that we can delete them easily.
  augroup vimrcEx
  au!

  " For all text files set 'textwidth' to 78 characters.
  autocmd fileType text setlocal textwidth=78

  " When editing a file, always jump to the last known cursor position.
  " Don't do it when the position is invalid or when inside an event handler
  " (happens when dropping a file on gvim).
  autocmd BufReadPost *
    \ if line("'\"") > 0 && line("'\"") <= line("$") |
    \   exe "normal g`\"" |
    \ endif

  augroup END

else

  set autoindent		" always set autoindenting on
endif  
"has(autocmd

"source ~/.vimtabs.vim
set linebreak
set textwidth=80
set wrap
map <C-D> <C-]>
map <C-A> <C-T>
map <C-O> :split<CR><C-W><C-W><C-]>
map <C-B> :vsplit<CR><C-W><C-W><C-]>
map <C-S> :w<CR>
map <C-C> y
map <C-X> d
map w<Right> <C-W><Right>
map w<Up> <C-W><Up>
map w<Left> <C-W><Left>
map w<Down> <C-W><Down>
map <C-l> <PageDown>
map <C-p> <PageUp>
:map <c-h> :nohlsearch<enter>
map ,tc :!ctags  `find . -name "*.[ch]"`
map ,tcb :!ctags  `find ../ -name "*.[ch]"`
map ,ts  /\ $

set ts=8
set sts=8
set autoindent
set sw=8
"ignore case during pattern searches
set noic
set showmatch

"abbreviate
set expandtab
:set tags=./tags,./../tags,./../../tags,./../../../tags,./../../../../tags,./../../../../../tags,./../../../../../../tags,tags
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
autocmd BufWinEnter * match ExtraWhitespace /\s\+$/
autocmd InsertEnter * match ExtraWhitespace /\s\+\%#\@<!$/
autocmd InsertLeave * match ExtraWhitespace /\s\+$/
autocmd BufWinLeave * call clearmatches()

