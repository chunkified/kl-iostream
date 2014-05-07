#
# Copyright 2010-2014 Fabric Software Inc. All rights reserved.
#
import os, sys, platform

includeVars = {
  'FABRIC_EDK_DIR': "Should point to Fabric Engine\'s EDK folder",
}

# help debug print
if GetOption('help'):
  print ''
  print 'Fabric Engine extension build script.'
  print '-----------------------------------'
  print 'Required environment variables: '
  for includeVar in includeVars:
    print includeVar + ': ' + includeVars[includeVar]
  print ''
  Exit()

# helper functions
def which(program):
  def is_exe(fpath):
    return os.path.isfile(fpath) and os.access(fpath, os.X_OK)
  for path in os.environ["PATH"].split(os.pathsep):
    path = path.strip('"')
    exe_file = os.path.join(path, program)
    if platform.system() == 'Windows':
      exe_file += ".exe"
    if is_exe(exe_file):
      return exe_file
  return None

#determine the suffix for the extension
extSuffix = platform.system()+'-x86_64.'
if platform.system().lower().startswith('linux'):
  extSuffix += 'so'
elif platform.system().lower().startswith('darwin'):
  extSuffix += 'dylib'
else:
  extSuffix += 'dll'
Export('extSuffix')

# try to find kl2edk and kl
kl2edk = which('kl2edk')
if kl2edk is None:
  raise Exception('kl2edk could not be found on the PATH.')
kl = which('kl')
if kl is None:
  raise Exception('kl could not be found on the PATH.')
Export('kl2edk', 'kl')

# setup the environment and define some methods
def RunKL2EDK(
  env,
  targets,
  sources
  ):

  targetFolder = os.path.split(targets[0].path)[0]
  cmdLine = [[kl2edk] + [sources[0].srcnode().path]]
  cppFolder = os.path.split(sources[0].srcnode().path)[0]
  cmdLine[0] += ['-o', targetFolder]
  cmdLine[0] += ['-c', targetFolder]
  cmdLine[0] += ['--overwrite-cpp-files']
  result = env.Command(
    targets,
    sources,
    cmdLine   
  )

  return result

env = Environment(ENV = os.environ)
env.AddMethod(RunKL2EDK)

# find the third party libs
for includeVar in includeVars:
  if not os.environ.has_key(includeVar):
    raise Exception(includeVar+' env variable not defined. '+includeVars[includeVar])
  env.Append(CPPPATH = [os.environ[includeVar]])
  env.Append(CPPPATH = [os.path.join(os.environ[includeVar], 'include')])

SConscript('src/SConscript', variant_dir = 'build', exports = {'parentEnv': env}, duplicate=0)
