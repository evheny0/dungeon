p system('ls ~')
print "\n\n\n"



CC = 'g++'
libs = '-lsfml-graphics -lsfml-window -lsfml-system'
dirs = []

Dir["src/**/*.*"].each {|x| dirs << x}

dirs.each do |file|
  #system('#{CC}')
  p '#{CC} -o #{file} #{libs}'
  p %x( #{CC} -o #{file} #{libs} )
end

puts dirs