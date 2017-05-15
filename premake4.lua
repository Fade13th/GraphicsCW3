--
-- Building my Tutorials with mingw
--
-- projects commented out did not build clean.
--
module = {}

module['src'] = 'World'

-- change above to match where include files are.

solution ('Tutorial')
    root =  'windows.' .. _ACTION
    location('./')
   configurations { 'Release' }
      language 'C++'
      project("glibrary")
          print('glibrary contains ...')
          print('      stb_image')
          print('      tiny_mesh')
          print('      tiny_obj_loader')
          print('      utils')
          print('      vertexbufferobject')
          print('      glslprogram')
          print('      glswprogram')
          print('      imgui')
          location ("./build/" .. root .. '/glibrary/')
          kind 'StaticLib'
          targetdir './lib'
          includedirs {'include'}
          files{'src/*.cpp', 'src/Components/*.cpp', 'src/*.c'}
 
   -- A project defines one build target, this define many
   for d, x in pairs(module) do
        print('target is ', x, 'where', d)
        Target = d
        
        project (x)
            local prj = project()
            prj.location = './build/' .. root .. '/' .. d
            targetdir('./' .. d)
            kind 'ConsoleApp'
            includedirs{'./include'}
            includedirs{'./' .. d}
            libdirs{'lib'}
            links{'glibrary'}
            links{'glew32', 'glfw3', 'opengl32'}
            excludes {d .. '/' .. '_*.c*'}
            files {d .. '/' .. '*.cpp'}
            buildoptions{'-Wno-write-strings'}
            if d == 'Physics' or d == 'Physics2' then
                Cinclude = 'C:/msys64/mingw64/include/'
                includedirs{Cinclude .. 'bullet/'} -- required because the way includes are done in bullet.
                links{"BulletDynamics"}
                links{"BulletCollision"}
                links{"LinearMath"}
                -- links{"BulletSoftBody"}
            end
        end
--~     