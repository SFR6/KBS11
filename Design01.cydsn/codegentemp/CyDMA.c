eyName))
          {
            var folderObject = subkey?.GetValue("InstallLocation");
            if (folderObject == null) continue;
            var folder = folderObject.ToString();
            var possiblePath = Path.Combine(folder, @"bin\rider64.exe");
            if (File.Exists(possiblePath))
              installPaths.Add(possiblePath);
          }
        }
      }
    }

    private static string[] CollectPathsFromToolbox(string toolboxRiderRootPath, string dirName, string searchPattern,
      bool isMac)
    {
      if (!Directory.Exists(toolboxRiderRootPath))
        return new string[0];

      var channelDirs = Directory.GetDirectories(toolboxRiderRootPath);
      var paths = channelDirs.SelectMany(channelDir =>
        {
          try
          {
            // use history.json - last entry stands for the active build https://jetbrains.slack.com/archives/C07KNP99D/p1547807024066500?thread_ts=1547731708.057700&cid=C07KNP99D
            var historyFile = Path.Combine(channelDir, ".history.json");
            if (File.Exists(historyFile))
            {
              var json = File.ReadAllText(historyFile);
              var build = ToolboxHistory.GetLatestBuildFromJson(json);
              if (build != null)
              {
                var buildDir = Path.Combine(channelDir, build);
                var executablePaths = GetExecutablePaths(dirName, searchPattern, isMac, buildDir);
                if (executablePaths.Any())
                  return executablePaths;
              }
            }

            var channelFile = Path.Combine(channelDir, ".channel.settings.json");
            if (File.Exists(channelFile))
            {
              var json = File.ReadAllText(channelFile).Replace("active-application", "active_application");
              var build = ToolboxInstallData.GetLatestBuildFromJson(json);
              if (build != null)
              {
                var buildDir = Path.Combine(channelDir, build);
                var executablePaths = GetExecutablePaths(dirName, searchPattern, isMac, buildDir);
                if (executablePaths.Any())
                  return executablePaths;
              }
            }

            // changes in toolbox json files format may brake the logic above, so return all found Rider installations
            return Directory.GetDirectories(channelDir)
              .SelectMany(buildDir => GetExecutablePaths(dirName, searchPattern, isMac, buildDir));
          }
          catch (Exception e)
          {
            // do not write to Debug.Log, just log it.
            Logger.Warn($"Failed to get RiderPath from {channelDir}", e);
          }

          return new string[0];
        })
        .Where(c => !string.IsNullOrEmpty(c))
        .ToArray();
      return paths;
    }

    private static string[] GetExecutablePaths(string dirName, string searchPattern, bool isMac, string buildDir)
    {
      var folder = new DirectoryInfo(Path.Combine(buildDir, dirName));
      if (!folder.Exists)
        return new string[0];

      if (!isMac)
        return new[] {Path.Combine(folder.FullName, searchPattern)}.Where(File.Exists).ToArray();
      return folder.GetDirectories(searchPattern).Select(f => f.FullName)
        .Where(Directory.Exists).ToArray();
    }

    // Disable the "field is never assigned" compiler warning. We never assign it, but Unity does.
    // Note that Unity disable this warning in the generated C# projects
#pragma warning disable 0649

    [Serializable]
    class ToolboxHistory
    {
      public List<ItemNode> history;

      [CanBeNull]
      public static string GetLatestBuildFromJson(string json)
      {
        try
        {
#if UNITY_4_7 || UNITY_5_5
          return JsonConvert.DeserializeObject<ToolboxHistory>(json).history.LastOrDefault()?.item.build;
#else
          return JsonUtility.FromJson<ToolboxHistory>(json).history.LastOrDefault()?.item.build;
#endif
        }
        catch (Exception)
        {
          Logger.Warn($"Failed to get latest build from json {json}");
        }

        return null;
      }
    }

    [Serializable]
    class ItemNode
    {
      public BuildNode item;
    }

    [Serializable]
    class BuildNode
    {
      public string build;
    }

    // ReSharper disable once ClassNeverInstantiated.Global
    [Serializable]
    class ToolboxInstallData
    {
      // ReSharper disable once InconsistentNaming
      public ActiveApplication active_application;

      [CanBeNull]
      public static string GetLatestBuildFromJson(string json)
      {
        try
        {
#if UNITY_4_7 || UNITY_5_5
          var toolbox = JsonConvert.DeserializeObject<ToolboxInstallData>(json);
#else
          var toolbox = JsonUtility.FromJson<ToolboxInstallData>(json);
#endif
          var builds = toolbox.active_application.builds;
          if (builds != null && builds.Any())
            return builds.First();
        }
        catch (Exception)
        {
          Logger.Warn($"Failed to get latest build from json {json}");
        }

        return null;
      }
    }

    [Serializable]
    class ActiveApplication
    {
      // ReSharper disable once InconsistentNaming
      public List<string> builds;
    }

#pragma warning restore 0649

    public struct RiderInfo
    {
      public string Presentation;
      public string BuildVersion;
      public string Path;

      public RiderInfo(string buildVersion, string path, bool isToolbox)
      {
        BuildVersion = buildVersion;
        Path = new FileInfo(path).FullName; // normalize separators

        var version = string.Empty;
        if (buildVersion.Length > 3)
          version = buildVersion.Substring(3);

        var presentation = "Rider " + version;
        if (isToolbox)
          presentation += " (JetBrains Toolbox)";

        Presentation = presentation;
      }
    }

    private static class Logger
    {
      internal static void Warn(string message, Exception e = null)
      {
#if RIDER_EDITOR_PLUGIN // can't be used in com.unity.ide.rider
        Log.GetLog(typeof(RiderPathLocator).Name).Warn(message);
        if (e != null) 
          Log.GetLog(typeof(RiderPathLocator).Name).Warn(e);
#else
        Debug.LogError(message);
        if (e != null)
          Debug.LogException(e);
#endif
      }
    }
  }
}                       	   Discovery      Packages.Rider.Editor                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   MZ�       ��  �       @                                   �   � �	�!�L�!This program cannot be run in DOS mode.
$       PE  d� [-pX        � " 0     �                �                         @    Ȭ  `�  @      @                                             @  `�          � E          �%                                                                 H           .text   �                           `.rsrc   `�  @   �  
              @  @                                        H     P   t                                                         (  
*BSJB         v4.0.30319     l   �  #~    @  #Strings    T     #US X     #GUID   h    #Blob         G  	    �3                             �      
 o
 6 � *   ^ � � � � � V� "� ;� u � J � ( � � � � � 9�               A   H     ��  	 �  �  �
 ) � 1 � 9 � A � I � Q � Y � a � i � q � y � � � .  # .  , .  K . # T . + g . 3 g . ; g . C T . K m . S g . [ g . c � . k � . s � �                                        Class1 ClassLibrary3 <Module> mscorlib GuidAttribute DebuggableAttribute ComVisibleAttribute AssemblyTitleAttribute AssemblyTrademarkAttribute TargetFrameworkAttribute AssemblyFileVersionAttribute AssemblyConfigurationAttribute AssemblyDescriptionAttribute CompilationRelaxationsAttribute AssemblyProductAttribute AssemblyCopyrightAttribute AssemblyCompanyAttribute RuntimeCompatibilityAttribute System.Runtime.Versioning ClassLibrary3.dll System System.Reflection .ctor System.Diagnostics System.Runtime.InteropServices System.Runtime.CompilerServices DebuggingModes Object     � �Ճ�TO����HG#       �z\V4��        TWrapNonExceptionThrows       ClassLibrary3       Copyright ©  2017  ) $d30b595c-284e-406e-b0a7-c1b8c774ef01   1.0.0.0  M .NETFramework,Version=v4.5.2 TFrameworkDisplayName.NET Framework 4.5.2      [-pX         �%  �  RSDSd{�vͼ�B�
pON�S   c:\users\huversee\documents\visual studio 2015\Projects\ClassLibrary3\ClassLibrary3\obj\x64\Release\ClassLibrary3.pdb                                                                                                                                                                                                                                                                                                                                                                                                                                    (  �   � �   8 �             T    P �   h �   � �   � �   � �   � �   � �   � �	    �
   ( �   @ �   X �   p �   � �   � �   � �   � �   � �     �    �   0 �   H �   ` �   x �   � �   � �   � �   � �   � �    �     �    8 �!   P �"   h �#   � �$   � �%   � �&   � �'   � �(   � �)    �*   ( �+   @ �,   X �-   p �.   � �/   � �0   � �1   � �2   � �3     �4    �5   0 �6   H �7   ` �8   x �9   � �:   � �;   � �<   � �=   � �>   	 �?    	 �@   8	 �A   P	 �B   h	 �C   �	 �D   �	 �E   �	 �F   �	 �G   �	 �H   �	 �I   
 �J   (
 �K   @
 �L   X
 �M   p
 �N   �
 �O   �
 �P   �
 �Q   �
 �R   �
 �S     �T    �             
 n   0 �o   H �p   ` �q   x �r   � �s   � �t   � �u   � �v   � �w    �                   �              	  8                	  H                	  X                	  h                	  x                	  �                	  �                	  �                	  �                	  �                	  �                	  �                	                                                                                                                                                                                                                                                                                                                                                                                              	�5�զ B��MUIrS�y+,�r"��������� w�y�;kW<�S�Eh��q'��'}�����'��7��6�
!W44��p�;>	Hj�=	��A�;T���[�}=L�c�C,��Ѓ����2�F>62�ȓ�q�K
�H Cd��snm��<1���t��BU�����ۉx9-aT�l
u��������h���E ��C�b��f��ŵ�ҳ���B�}A˹��yZ��9A�3�
�q:��$_*/�Zs����Yj�_Y��2T�BT��*�Z��Q���?�K�
�l0�$�=�}9�ae�F��BLm�a1��whl�{ax�ND��)�Mr2O���d�Sno�1P� �!�sX�����|p����R�3r��(o ^�N0Ru;�5k�n���6v!J�|:�$:���H��ޚ�s�>�´8����h 3~+ L��:�fݵ`EcH�Z'��W���cԬ�i�r�-.��Cv.���-�O �tiXf�%P�ua�b2���d`ɏ`�8/�ZF����?p�O����:���P�e�~)4���ў���E����U�.�c���3�2zy?9����Zǅbm�x��.!K ��{$��5��ҡJw%/�S�� Or���!�bt�*��]�P~I��=T%y�S�1d���#"���. e:5j]I�%�����@���]�:�d�a��Rha�p3�J8���9��Lk~	b�p���H���L�J�M��*�6U�	a�i�X����`�_��2*�P��&l�J6Yh([4�<�����}T3g�)�\�^�=t<xdo�H0P^3��j݅�E�o��<xD}��=���q���D����>] $�,��&�GdwI1B_�~~6K ���i��h03ւ��c�+��<���H�S�%�&���Hqrq�8MH|CN%�1csnV��i�X"���M5>�j|L���&����`ER�=���1�! &���\�Na�	��leQ�5���f������6�k��d�}����^��-|�m[�U���u��������r�^�k��E��Z�Q4��姞7�4��#Z��}ʙ��#i<��s>Ō�Q��{|u<�h��$O,|I��T�0H�SşbA�᮶xK��R-{����H'if�Os'��s��&��g���?�o����-:o /�.>��K��I�0L]Zo����tcಗ�"V�\M�P�`��Z�e)����	<�b���a��g녮��b���7���k�x7x��^����Ч܏��Г�\�|{XP�(��K -�0�`�fq���)IB�^���` 2:�r��K'!��EȨR�����姕u����*f3b�d˯/qԱ�׆�Ktc��5[\����ejB��8Z���z�O�`'B �5(���,�.M��YH�i�}}1=���\�]l����E��V�6?]��uEYA2n֡�	Mgƿ�ųzʿ=f��7&^g�:quEi�pe�<Ҁ�u�to�lF�Ң��%2u
�E�x���.O:4�K�;����{oj4h�Ј>k�X�U�<6$�KP��%�uE{�^·���*6��J��E?��쉼�i0w��Ǹ��"��vsw���2`�E+��Ę�.�וH�;�&h� ��]4'w�ro�R�y޹!"�ۘ��Dn�r[иH��#u��5�tS5(�*(�ꡗ3�N��~ԱKEŢ/����T��V���0�՚�.�$�����_��s���me��aV]��5j���ﭯ��g8k�t3d��f�;t �d�$��9�0XFλ��b��~�Z�P/I�̆C(hߜr�rQ$NH�>��ݺ�%���.��\����`6�� �J�����˚�za��iY��?�s�8��(δ��+�!�0Z��(�8�Cp]�OWhwQSG�ՁRe}����Z�,^�n�i?��	���|>�\�X���5/�{�#ET:7Y�n;~�M���_h�Vz�?ٷ����%�ǂ���8]����~Z��;\Hع'Ȧ��>̽�K��A��m�".����pkMM�:�o��U�`C�2^,p��ו��嫮j|ӯ�=0I�Gb�>H]+>�R�^�.!�U���D��"y��&�滓����k:V�5K�*?���j�wej�[k�]��W��ܣ�����OW�C�hKi�ZX���~Գ���l��_`p�t���_河�h#cLf���ϲ�|���*��m����G�A>�ߠ����1����Ӫ��o�1Y?��ex���[���Ct����a+zUi�ժ���U�Q���d�$�Z9�@��m���B˽Q��SJ�^���[pZ��k���Pj[�뫕�N�9�o�����V����a�뫅@�}�:�{it�xsf���&�Ԡ�K�[�FS���9?�0��X[ h�bWtF�ۃ�Jk~���e�v ���9�={���\W�pm�Z$����I�LyE�|��O(|�<�DcL��+O�j�ߢ<�2L$�j�4A�9�z�5���;�i��'��t��$�;�(�jBNbp:~Ф>�ym4<���}u-q�!���x�½Joa�L��ŗ��MA�OO5��z9�����h�>���s�O�|e��E�S#���Y>՝�8ȏ@����&.4r�F�E�IT�+~^$E4%!)��p��,��k���r�{��G��Jw��3h*ޒ���-�{\�]��?I<�zw��Rۖ��j:��|=H��9���-��n�l�I��ǒ�[�*ɏ(ߩ]�~�Gp��h����;��a�ĮJp#'P�;c����ޝڦ�a}D��4��l3�˙�{��ՙ�}9$��V��3�A�=���Z�0�U�����՜g�eo�K��^��U��w�є��$��CcygZWT^���uE箻�]�n�f5jP�Q�9� �s�٘��9/���ז�i̬Z��Ak塎y���B8@��Js*_V���ę��J���4�a~��7L��1�<����8��nE���̆���k�g�����6���3r/u��\��84�>��/�/	�l���n��6^�=�ԣ�*d^�4����&ŭ<B�3�$g�z�{'�H���/���R�hc������ 3�W�C07^|6
�`}�T����r@�x��.��3izl��8�;��?��w���>$N%O���H9���r���A�}���4pI?oo�E��������zy� xQ����Ó>�j|�oH�R0酳t��̐v��D��a:3J�9�#$�r�!𞔥^��� ��)�>���]����8�:P���n�YR���:�nM���:��ŉ?�D�0�� ú;^��j��E��B�W�%y�����b����H��K��p�T�U�NM0��;h�/���EcN��}:I��W�͗�5Ye�9j\lP�����$[!���
Mr��=���͗�W0Xܮ[ >]�\"~��6��Tg�ZW��7�y|���;�PW�l�� t�?�Nj�w�[�.�<���Jz�DI��,j
��*�Ԯ�7n}��JK������A�[�73��,^��A
��oZ�%[%@I��ʀ;tx=�}�[ϰ���6wNG�d���[!���ϺD ;C�����3!�2^>����s��%Mj���� Z�� W���G`co�I#���y�6�P�r,=�7s9��X��Q�,5�L �FGZ0����O^Xb�.���t&�c6{T4���.�5'�1Ř�Q��/q�� o�bY����� Ο����:�[�{�j�.
#�ɻ�<�%R�J�M�,`�i�����X�7f��|A��`:�8����=`�}�h�4�8��ȹ�6�7��r�����u�X���$&�ɶ�*�t���ߓ/�=���U�A2�qG��V��)��-/�˟�����͖�Co��25�?&en%u}��j84��b�D0V�ǡ�F��
���9d��ď�t�����M.�i^�@�	/"R���9�����C8�,�����#��wm��+�x[�@�\<���4e��|Λ6�9Mq}XތS����&d����y�fmN5HHc:��ހ�fO`.��R�\��-���)ͨ����Q�.�pk����*!۶���� ћ[��s�h�xR�A}ݔ�5�M�R8*O[�N���K`J/� �E1LA1���΁��nA*�}Y%�%�Kp�;��FmEԃļ&��&�i
�Na���5�� ���w�X?Ro�Sc|��j�� �T5Z&��\ῂz.�R�P��U�#�����h�i�d�`3�E�f%�j�ˏ�,�+�H"�}�0V!�Ѡ��fD�7ZLEvjcz��np瞔�Ǐ��j��v�'K��{�eS̀���N��*�:�[�� 5�*
����5�䂙��l�Q�w�K`)L|0[ܠJ���P���4���m z=��a�U2ۊ�_*H�N?!����iк�	�O;�۷�r��q$��B�/������I-�&ㅫk�����L��-�qp.�N]�Ki�
%*�YYoC�P�+|]��k7H�����bBH�x{��PI��|��W����eb>�P5���2���݁�ȭ��lD$�?;%��) j>���A����wz��>�2zW	Fe��C��K�A��ၚ+�ը,`�uX�h	�����؞��� �I��b-T�Ѳ��x�$�2f*D[O��.P�[c��"k7M�S�q�\�����g��p0��@Q#��%,a�j������0�K0JU�J�,!�
J`by�a��ٰ�|�JP�;�?�ذ0(���]!����\�]y��_i�G�3~w&Ѳ��G��$1X�A���.�2i��$q�ʮP�"XX,Yǔ��K%��Q��y�Z������p�'$^0u@���mɿe��|
l��D��c���q��o������ @�4�EI�}a�%���W"e��i�$�t��'ܿ9����$%�O~�� ��%��Ь��(m� )�?4ڣ(�3�ˁ��~)^pk9N
��J�{�М{�-�P�G��AQ�s�_��X��b�e�{R�PM�h\�q��"֘��Q昊'R�i�KX���j,#�v��s���G�<�W�Z e�2�]w�A�x�UF`���T!�E0�7���E0��+O�.��y���c3|6H��!]�X�j���:�$�<\sY|��$���<t���"��ʝ-��p��^B�|U�ȳZ*�pB��j�Ul�"\��%�6���A�[7,�<.���Z�\�T���z)�Y�!1�$�8P�?m��!�C��a���[(^����p@۶��5+W�FY!�6��z-�C��ࡷ�����a15z��ŴJ�A���$'F�g]���V�gi�ݏK!J4�Sc;di�
����9Mد�j��E�T8$���$�X��3��&m1� �����Uv�s9c�g��\�K|E1ޅ"K�^���1�ic��"T�`	aL'p�������RE#.�e�U���'Ɖ>Eϧ��=�����n�)+'�d4����vD�T�I�Uh���`h��-"ΣE1~�YB�(��Y�w�<�����B�pZ}T�Hl7��A,��	RC�ڬ*��n�P���Rq����V�O�/z��B�o���1�W���@]$�bym�-��p����M�cHM�PW�iS� SkXN3�1K�3�b�ݏ���1i����(������^O�H
�����	=�P����%`{�n���i���V��RB>P�T�;9�BIxH�R�<qE�"�׵E�^��gɥxB����%�Rб���~U �#�\ć�X�b4���F�s��q
(Z���P� �[?�"�O(AU_�Q�Q3��y�L�W~E��O�
�����(C��=���.B�z�L*L�������t��R����J<F��7�HKp��.����u��Y�[L�� ��҅vQiߌ%(6*������ �a{�H����:\�r�Ӕ|x��2h5;����.�?Z�U���Ai�{9̋AŹ2��>:��<?� �37�N0�$&���>���0�Vb���@�������2��?|������6#{`{��ca�2 ����%<­�e�dN�Α<+?�P��j�|���)Ҕ�7�Ď���P�H�P9���+3����|} ���z]?���;�� =���� ��P����,�: `|�ZĀ����"�x:_����)�i��X�R���&��P��n�g2���'|莺�1���"h	<G�c��ї�̭C�HF���Q��,��.DXa���kJ�s��t�M4�IX�=Y���A��g�[|>�AO�>�hvB|}��=0���4��Mg�(�1��u�EH��9p�L���_���Fc�|-�i�l@��x�^�0��^�*¾�	�qѕ�r��I�VH��r^w/7��m����璕zn������Q� ��&�5A<+D�ʔq��:�0>N�2,�G�,^D�|��9�?������>t�4ֱ[�Eh/��[���_�F	[��%??�3N��/hP�l��Y���juV�L�n�g($��9�"�!�Δ���:�}�Ϩ�"K#�p���;e�f1�+���5/�C����3�OE/��Cj1O�� �+@��@"�f�	H^KI�P��w� !�)��{�ȀY� V�G�l��h���P��i�{��(\n��j
���E��I�q�A����"޴��
�x�����Ņ��jM\��U�1�(h�((0��	��^�%���Ij��}p��3����h	N|	��3�~��R|<nX�F \�)��)V��%�ۧ�£�&ȷH�5.�D�i�����/�Њ�
t�S��?Eo>'��2V(��@�(/5L/��Xe��
��77�r�Ph!_�F깛;6(��2�Z�H�
�atU����� /��q�ڂWr&9~���O��ìIH��}��R�<ViF��4��
�Yx�C�Q���j�R�3�+�Y.-BE��[���a��8=���42˞ZJ��+U��j�d<��|ߝxb���2#�$ W7�iߊ��1!ق o�0&�ǆe\���F�����D��q&y�[��Y����,S�J,S�s�"8�<���8�{i&���Q~h�#��+\���w	��3� #��3�2���e�'as�����q�=��@z\�/�Ԕ��@���r��
�np[���E����e�B$�=d��U�b6�B�R��i��i�� seC����$�9�V6m'�D
&�6��M��,9�˼rfr�}ߚ�n��.���p����$�5V�W�0��r�Ջ=�|	4s�Y���|�$��/!�ɑY��p�W��İ��.�3������P����]��#V fk��x�ӥ�`Z7�_��*{�ifPz�J8/������uCqmsu�5�ݛx���1;�iV��q�=ej�~�B�a-T��η�� ��<�hS�%.���(/�bG��1ל�gb��m��8���z�3WZOk�܀P'eB��{��"�p}8���3En�
02�J�����4_+��N,|��ޡ	��	�*ee��a[n�t)� D>�iC!{�|��ي=6���j�`Q8n��ن�9N���Q��^�Qv'L����5ڎ�D���zG�Qkߦ0-��B��;.��w.z�d˖B���oJ��n�s훩�J����3C�F�]�ti�Zu��đ)�	q�3z
vW�(&c�*T����W�Z#
�j#�-}\�̩f�9==�¯_xݍe��O������4X-�5�.��,�.��,����� 1`����=�[
\�K�b�*�Z9��N�n%'U���n�=���[p0������8IGU�2m�Ά1sqY�k���wCz�],eV���~m};JS�א2��3
d�����/NU�ס|��i"�OB��<H5�kx��@�<�ɴ������
�^��ֵ��������霱��C��W�a���u�9�P(��.�E�l�6+�J��-�WzT2��2���`�|>���(L6+l���/~���͘����%XJߥ���+	�
^~W����!'�KIT`A@)+����O2�Hf�
ɯLw2ӄ ��n`����w��ώ��S�tjNݽW�w�,�+�4ѭ�hW�:=�`�u� ې��Bꊝ6(?|�BQ_ca�2h���Vd$�.� Cc�|���w��8������R����xi�k�iíӺ.�r�Q��$��&��"��P{iy�E�$�.��V�LX�!_�f�/)~P���ہ�����e�`� �
��W����Wx�f��y�~>�i���=Pe�ǣ��X�xe$�{Q�Ll��r�X����F�,~c����,��J ��^sӰ�,����L
�`G�'3��	!H*�����0�c��b��n��������c���cF�k��"^
 y_	h�U	�;�tɤ�Y�V���������X0v���� ���J9��8��jȔ�����L$*�NEЇ�LZq�e���`�By� �n��Jy�ɢA�3��M8Vp� �wb^�6:@��d�$��L1NO�������2���C+�3/a[�,T�V�e�ړfe�#����N7H��+� ]�J>1$#a�!�2���k2X��SN��o) ���2S��`q,41y虠d�����������sy*_��E���F�,4�B��>̙���Y�i�{g�Ma)ȏ<���4be��V(��l��*�n8d�Fލ1�J=�����w�֜N��Nƪ��:qv|ϟ)C��m. ��g>]7��T�`s� )����E/����2'�P���ק7~��A��1�3����	+"�Ͷ���8'Q4�� ��M�Ӥj!+v����`	?�^��<^�g��f[ | �!�<3RG�E��z�;?�zf���LE�j��>3�6fN�� �f��}������������NmIw���)�h�p}��́[A���7���	��$	��[#H�K>d�^�����,�%=Ov�+Q~l��dJ������:e�u�Ki�Zƚ�!�8�����.,��v�'�֫re���Ein�.���UUWՕ��΢y*�d7�+�6�2�eTF�S|���ʖ]Fo��&Qu�T�U$Ż$�)=��_������y���o�@��R�nu�}������W55�i	/Cϫ��Е�)�*"Y�"W�䏧��^$����g��9�+���`�u��<|��ʽ��W�R��I|�W=��ad(��{�U5WU�t�y%�>�l4��h5=�^�f:�v���,�t��%	����Uި����QI����@�/ �s�/K�:�e��Bj̻�0|�{?N�҈[>1S�i�͚/EL6����߲tI�)��ڢ/Ub˟�@TV��y���.�&����4�X�y�>��K�=�2��<���Oy�=�"Wb���`1��2�����5�W$��0Ђ��2���7Pj��z��L��QO\>����
�n���-2Ե���+���qL��� �r렿��V!y�r���$�x�~,H�����.��Yc\�x:t���f��
X��y�uD>��u4G���P�%�J��_?�u(�O��9~���Xf<���C�V
d%�4˽Jk#TB��ҷ\F�5�ev_������9^���!��o���'���OF��D�m��μ��u�g�}t՘�(\�mw�xo�W�A唹�_gBp?Y�×?хl�P�f'Z�и�n��a�o�,Wx�k�|Y5���:��e*lS���������Z��[�z^��Jd��.������|5�R��L���7��!#M����]�Qu�-��5ծ/�r�>�<�0���z�{�d=Q�AVpzN�f��.﬊�e`��sR���@�t6Y���hzI_Af���8�F�6u7]50�
�J����u5��	��|�HN짰vl�}����T�0|\�'J��K��e����#���?'ɓ�Km�_�����t9�}��*���u�����%���D�S�*u��2R/����&�7�]W#���_H&wGF��fOg%��'�YqO���p������mc��]4ö[�t�:٠U�/y�$ ����� �p�Œ X��g��Jŋ�	�!Z\�"�^O�\~��p<�#�|^�g��Ƙ�TQ��9�� �7~��SEd�9��N��.��v�E���E�Ǧ(^�o���\I�U��*O�WX�y�݂x�z0Fl�����n�
�t�}�ez��mW_��![o!�!��@ܨ&���F�����#�.���l�t��"����#^n���p<����m�Q��a��Yu�c>ќ�,��X��ZTEB�m���aw�E��R\�{И\�zP����s$�
ٍ��V���p�L�T�z�9[�ҝۗ ��A��(ؐm%όUQ9|�ϳ�k��i
����ܼ���1�#[j5�7�l�jK|[?��@�ܯ���:�v>���=-i���@��9��D������,)|+������7��l��}�����p� 窦;{�T"q�Y�]�����;
Z_�h#�����f���%.+��z������M�re/�7��0,�9��$�B>�] o�s���o�hM�ɚ���������U.��H6}����J�"�C�lD�+Q�	�$:m�k�Jw)��ͽȱR��$�7x��O��y���p#VQ�]��Ⱦ�{����)��E=�fy:{��EF�y��dց�j"1�vM�*h!+��#յ���҇f�Ѧ��6i��ΏQ�,=y�D��t���dk�^F��� x�!���[��V�~��:��|�܏m-IL�������8$�&/?�m�⧀�Ǐ@;P1�,#�#�c�F�M/C��R�y:�K��e/c����}1�T]�fdy�;�Fŏ`����.�|dq�C�w*(X����l���8��J߬&�%���
�Ͱ�dy$�4�R�m��Э�$t�����f�
j�+�]X2ڠc�h���<�.s�'�<���K��)�)�l��b#����EPI��x���i�D�9/���U�ٜ���ȕDZ�H�,Յ��R�-��ZyZ�&�+�l�j�@�	�q��01����J��<E�޹����u�>�Z�Q�V@��fS��%�a<8�)j>�n�D�g�cr�����R���ך�}��T.֬�^%���U�Z����r^6�mz�!���0�q/��H؃Y�Ӣ�f��y�P,L����9�����ij|iR                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     �^8H���= I�M�~@M�~HM�~PI��I�N@�#3������  N�<�    M�I�N@I�VHH��H;���   M;���   M+�I��E3�M����   I�I;VPvMH�� s8H��sA�T$�/H��s�   �"H��s�   �H��H�H���H���H��I�N@�2������tKM�FHM;�sI��I�V@J���~�: I�F@M��t$L+�I��H��tJ�(H�H��t�AH��H��u�M~HM���EgA�FXH�M��,���L�uoM�>��@��t"���H��t�ouH��   H��H� ��G= @��t$���H�M�H��t�iuH��   H� ��G= �@��t#���H��t�kuH��   H��H� ��G= �@��t!H�MH��t�iuH��   H� �iG= �H�M���+��I��H�Ę   A_A^A]A\_^[]��E �H�j�B H�M��: ��Eg �H�R�B H�Mg��: ��Ew �H�:�B H�Mw��: ̐�������H��L�@UATAUAVAWH�h�H��   H�E����H�XH�pH�x E��L��H��E3�D�mM��u[E��uKL9i(uL9i0t?H�U��&G��H�I�L�(H�M�H���p  �i�f  H��   H� �iF= �P  �AH�2�E  L�m�L�m�L�m�H�EoH�E�H�EH�E�H�Q@H�L$ �L�E�H�M���V H�E�H��u^E��uNL9n(uL9n0tBH�U�H���F��H�I�L�(H�M�H����  �i��  H��   H� ��E= �  �FI�6�  L�mH���i  D�xD8nXtA��E��E3�H�U�H�M��Y���H�H�Mo�H�]�H�H��H��t�C�   H�]H��t�C@��t���H��t�iuH��   H� �@E= A��t H�M�H��t�iuH��   H� �E= H��u/H�^@�~X�`   ��: H�E�L��D��H�U�H���J���H��H�EE��u4H�H��H���  ��D= ��H�H���  H����D= ;�uI��  H�H�U�H��H��(  ��D= H�8H��t�GH�}H�M�H��t�iuH��   H� �hD= ��kuH��   H��H� �MD= L���2H�^@�~X�`   �B�: H�E�L��D��H�U�H���|���H��H�EL��M����  H�H���  H�H���  H����C= ��H��H����C= M����  E����  H�H��H��0  ��C= L9(�  H�H��H��0  ��C= H�H��U�T$ E��L�EoH�U�H��  �|C= ��G��$H��uH�7(S H��taD8iXu[L�E�H�U��  H�L�(H��H��H�UH��t�iuH��   H� �#C= H�M�H��tJ�iuDH��   H� �C= �1H�H��H  H�H���  H����B= D��H�U�H��H����B= �H�M�H��t�iuH��   H� ��B= H�H��H��8  ��B= L9(txH��tsH�H��X  H�H��H��8  �vB= H�H��U�T$ E��L�EoH�U�H��  �QB= �H��H��H���AB= �H�M�H��t�iuH��   H� � B= I�>H�M��&��I��L��$�   I�[0I�s8I�{HI��A_A^A]A\]Ð�������H��H�PUVWATAUAVAWH��H��`H�E�����H�XM��M��L��H��e� H�AH�E@H�U@H�M��J���H�H�]@H�  H�M�H��t�iuH��   H� �sA= 3�L�vHM��tbD�}`H�F@H��H�D�|$ M��M��H�U�H��   �=A= H��H���	  H�M�H��t�iuH��   H� �A= H��I;�r�L�}HE3�D9cH��   H�FH�E�D8fXt�@��������MH��EH   L�E�H�UHH�M�����H�L� H��H��H�U@H��t�iuH��   H� ��@= H�M�H���B  �i�8  H��   �  A�   D9kH�  D8fXt E�ME3�H�S@H�MH����E��H�8H�MH�H�C@H�8H��H��tDoA�   H�}�H��tDoA��tA���H��t�iuH�A��H� ��?= E��tH�MHH��t�iuH�A��H� ��?= H�H�U�H��H��  ��?= H�H��tDjH��H��H�U@H��t�iuH�A��H� ��?= H�M�H��t�iuH�A��H� �k?= �f��ouH�A��H��H� �P?= ��FX�CXH�H���  H�H���  H���+?= ��H��H���?= I�I��H��$�   H��`A_A^A]A\_^]Ð������H��L�H L�@UWAVH�h�H��   H�E7����H�XH�pL��H��e� M��u�AH�
�  H�e� H�e� H�e� H�EoH�EH�EwH�E'H�EH�E/H�Q@H�L$ �L�EH�M��P H�E�H��u�FI�6�  H�e� H���E  �~X t�xD��E3�H�U�H�M�����H�H�Mo�H�]�H�H��H��t�C�   H�]H��t�C@��t���H��t�iuH��   H� ��== @��t H�MH��t�iuH��   H� ��== H�H��H���  ��== ��H�H���  H����== ;�tcH�H�UH��H��(  �}== H�8H��t�GH�}�H�MH��t�iuH��   H� �N== ��kuhH��   H��H� �3== �RI��C�C��usH��   H��H� �== �]H�^@�~X�`   ��: H�EL��D��H�U�H���B���H��H�E�H�H���  H�H���  H����<= ��H��H����<= I�>H�M��$!��I��L��$�   I�[ I�s(I��A^_]Ð����H�T$USVWATAVAWH��H��@H�E�����M��L��L��e� H�AH�EHH�UHH�M@�����H�H�]�H�  H�M@H��t�iuH��   H� �<= 3�I�vHH��tRI�F@H��H�M��H�UHH��   ��;= H��H���L  H�MHH��t�iuH��   H� ��;= H��H;�r��{H ��   I�FH�EXA�~X t�@��������MH��EH   L�EXH�UHH�M��ϝ��H�H�  H��H��H�U�H��t�iuH��   H� �R;= H�M�H���  �i�  H��   ��   A�   D9{H��   A�~X t!E�OE3�H�S@H�MX�ˋ���A��H�8H�MH�+H�H�UHH��H��(  ��:= H�8H��H��tD�   H��tD@��t���H��t�iuH�A��H� ��:= @��t"���H�MHH��t�iuH�A��H� �x:= �A��tH�MXH��t�iuH�A��H� �T:= H��t!�ouH�A��H��H� �7:= �A�FX�CXH�H���  I�H���  I���:= ��H��H���:= I�$I��H��@A_A^A\_^[]Ð����H��UVWH�h�H���   H�E7����H�XI��H��H��H�E�H�EgW��E�H�e� H�e� E3�3��H H�E�H�e� W�fE��-�@ �E��   H�M���  H��H�M��� H�e� H�e� H�e� H�WHH�M��Z#������   L�G@H�GHM��H�U�H�M��Mf���H�E�H�E�E��E�H�e� H�e E3�3��nG H�E�W��EH�e H�U�H�M���  H�E�H�EL�]�H�E�M��H�U�H�M?�+���M��M+�I��L�I��I���R H�M��j   �`   訾: H�EgL�OD�GXH�U�H�������H�H�M�����H�M��3   H��H��$�   H���   _^]��Eg �H�{�B H�Mg���: ̐���H�\$WH�� H��3�H�IH��t9H�G(H+�H���H=   rH�Q�H+�H�A�H��w]H����5= H�_H�_ H�_(H�GH�H� H�GH�@H�_H�OH;�tH�H���`5= H�OH��H;�u�H�\$0H�� _H�%C5= �]5= �@VWAVH��0H�D$ ����H�\$PL��H��H�
�A��$t�y@t63�H�^HH��tH�F@H��E3�I���2����u"H��H;�u�H�N@I���.���H�\$PH��0A^_^�I�H�H��0  �7= H�8 H�F@��   H��H�H��0  ��6= H�8 t�H�F@H��H�H��0  ��6= H��I�H�H��0  ��6= L��H��H�L$h������H�D$h�H����t�x8uH�F@H����R���H�F@H��E3�H�T$h�dQ���H�L$hH���/����i�%���H��   H� �J6= ����H���xR������̐��AXÐ�������H�T$USVWATAUAVAWH��H��HH�E�����L��H��H�H��0  ��5= E3�L9(t[H�H��H��0  ��5= H��A��$t;H�H��H��0  ��5= H��y8uH�FH��  I�H���k  �A�c  E��H�VH�MX�+����E��HcFHH�E�H�]XH���  H�~@J�<�H�}`H�}�H��t�GH�H��H��0  �;5= H�8 tnH�H��H��0  �"5= H��A��$tNH�H��H��0  �5= H��y8u2E��uFA�E��t>E3�A��H�V@I�H���;���I��H��u�H�}`�E��tIc�H�F@H��H��������ouH��   H��H� ��4= A��I��L;m�����E3�E��L�uP�#  D9kHuyH�FD8nXtT�H��������EHL�FH�UHH�M`蕖��H�I�L�(H�M`H����   �i��   H�A�UH� �4= ��   H��  I�H����   �A�   �{H��   H�C@H�H�MHH��t�AD8nXteA�   E3�H�UHH�M`脄��H�}`H��t�GH�MHH�}HH��t�iuH��   H� ��3= H��t�ouH��   H��H� �m3= H�EHI�L�mH�D8nXt�CXI��%�FI�6H��t�kuH��   H��H� �,3= I��H��HA_A^A]A\_^[]�@UVATAVAWH��H��@H�E�����H�\$xE��H��H��H�yH uH�AH���
  H�
H����  �A�  H�A@H�H�H�U0H���  ��2= A�   L�{H�   H�C@J��H�E��H�U�H���  ��2= L�E�H�U0H�MH����H�MHH��H��t�AH�MHL�E0H�E0M��tA�huI� �   I��H� �72= H�MHH��t�iuH��   H� �2= �H�M�H��t�iuH��   H� ��1= I��M;��H���H�}0 ��   �{X tdH�U0H�MH�\���L��H�E0I;�t+H�M0H��t�iuH�H��   ��1= I�H�E0I�& H�MHH��t�iuH��   H� �u1= H�S(L�C0H�: uI�8 t�d$( �D$  E3�H�M0��/��H�E0H�H��H�\$xH��@A_A^A\^]Ð������H��UWATAVAWH��H��@H�E�����H�XH�p L��H��H�QHH�e� H�e� H�U�H�M��������"  E2�3�L�gHM����   H�G@H��H�H�U@H��p  ��0= H�H�]0H��t�CH�M@H��t�iuH��   H� ��0= H�G@H;���D
�H�U0H�M��]���H��t�kuH��   H��H� �F0= H��I;��o���E��uH�0 u�GI�>�F�`   �(�: H�E0L�OD�GXH�U�H���`���H��H�E0H�H��H  H�W(E3�H����/= I�H�M��S��I��L�\$@I�[8I�sHI��A_A^A\_]��E0 �H�ݿB H�M0�0�: ̐��L�D$H�T$USVWATAUAVAWH�l$�H��   H�E�����I��L��L��3��u��Eg   L�yM��H�UgH�M�蝑��H�H�UH!0H�M�H��t�iuH��VH� �%/= McnHM���9  E3�H�]gL�ewI�F@J��H�H��0  ��.= H�8 tsI�N�� ��H��I�N@J��H�H��0  ��.= H��M��H�M���������u�L��S H��H�M��2X���A�L��H�UgH���/e �H�M��&����H�Eg�I�$H��t�C��H��H�E�H��t�@@��t"���H��t�kuH��   H��H� �6.= @��t$���H�MgH��t�iuH��   H� �.= �@��t#���H�M�H��t�iuH��   H� ��-= I�F@J��H��D$( �D$ L�S L�E�H�U�H��x  ��-= �D$(   H�d$  E3�L��H�UH�M��1���H��H�EH;�t+H�MH��t�iuH�H��   �e-= H�H�EH�' H�M�H��t�iuH��   H� �:-= ��H�M�H��t�iuH��   H� �-= �H�M�H��t�iuH��   H� ��,= I��M;������L�eoH�}wM�~E3�E8nXtiE�ME3�H�UH�Mg�}��H��H�EH;�t)H�MH��t�iuH�H�A�U��,= H�H�EL�+H�MgH��t�iuH��   H� �m,= H�MH����   I�L�mgD�l$(D�l$ L�MgL��H�U�I��H��x  �4,= H�I�$H��t�AH�M�H��t�iuH��   H� �,= �H�MgH���  �i�
  H��   H� ��+= ��   I��H�]ϋA��$tHH�H�UgH��(  ��+= H�H��t�CH�]�H�MgH��t�iuH��   H� ��+= H���QI��H�Mg����I��H�M�H;�tH�H�]�L�(H��H�MgH��t�iuH��   H� �9+= H�UH������H�H��H  I�H��0  I���+= E3�H��H��H����*= H�A�V H��H���  ��*= I�$H�MH��t�iuH��   H� ��*= I��H�Ę   A_A^A]A\_^[]�H�T$USVWATAUAVAWH�l$�H���   H�E�����H��L��H�A@H�H�H��0  �j*= A�   H�8 ��  H�d$@ H�d$H E3�3��6 H��H�EwH�D$@I�N@H�	H�H��0  �!*= H��Q��A"���   I�F@H�H�H��0  ��)= H��yT
��   3�I�F@H�H�H��0  ��)= H�H�A@Lc`M����   H��������
I�F@H�H�H��0  ��)= H�H�A@H�L��L�nM��H���4G H��L�|$HI+Ϻ   H;�r"L�L�|$HH�FI�E D��H�H�t$@I;�u��wH�Ro> ��%= �L�|$H�fI�F@H�H�H��0  �)= H�^L��L��H���F H��������
L�|$HI+�I;�sH��n> �W%= �M�L�|$HH�FH�H�t$@H�uwM��M�nHL�m��   M;���  H�H;���  A�   @2�I�F@J��H�H��0  ��(= H�8 �  I�F@J��H�H��0  �f(= H��A��A"���   I�F@J��H�H��0  �<(= H��yT
��   I�F@J��H�H��0  �(= H�H�A@Hc@H�e H����   H��L�}I�F@J��H�H��0  ��'= H�H�A@H�E3�H�SJ���m#��@�����   E�L�L;�u�H�uwL�|$HD���.I�F@J��H�H��0  ��'= H�SE3�H��"#����tA��@��tH��JH��H�H��H�GH�H�H�GH�AM+�L�|$HH�OH��t�iuH�A��H� �('= H����$= H;��s���L�m��   L��G���M����  I�^H�]�H��H�M�蔎���E3�M�nHL�m�H�}�M����  H�e� I�F@J��H�H��0  ��&= H��A��$��  I�F@J��H�H��0  ��&= H��yT
��  I�F@J��H�H��0  �d&= H�H�A@HcPI+�H�e� H�e� H�U�H�M��O������  I�F@J��H�H��0  �&= H�H�A@Hc@H�EwE3�H����   H�H;�tAI�F@J��H�H��0  ��%= H�H�A@H�H�SE3�J���r!����u>H�H��H;�u�I�F@J��H�H��0  ��%= H�H�A@H�N��H�U�H�M��,��I��L;mw�w���I�^H�E�H����   A�   I;�v[D�mg�E
   H�EgH�D$ L��L�E�H�UH�M������H�H�  H�M�H�M�H�U�H��tD)iuH�A��H� �
%= H�M��H�E�H�H��tDjH�M�H�U�H��tD)iuH�A��H� ��$= �H�M��D	��L�m�I�F@J��H�H�e� �D$( �D$ L�M�L�E�H�U�H��x  ��$= H��H�������H�M�H��t�iuH��   H� �f$= �H�M�H��t�iuH��   H� �E$= �H�M�H��t�iuH��   H� �$$= I��M;��D���E3�A��H�M�E�l$M;��#  A�L$��: H��H�EwL� L�`L�xI��H���������)  W��E�H��H�M����H�H;�tL�u�L�CI�VI���F��H�H��H;�u��E�
   L�M�L�E�H�U�H�M��c7 H�L� H�M�H�MH�U�H��t�iuH�A��H� �O#= H�M�H��t�iuH�A��H� �1#= �H�M�H��tG�����A��u1H�]�H�H��H� �#= �����C��uH�M�H�H�@��"= H�}�H�t$@�2H�H�PH��tDjH�M�H�U�H��tD)iuH�A��H� ��"= H�E3�H�U�H��H��H  ��"= L�uoI�>H�M�H��t�iuH�A��H� �m"= �H�H�6H�vH;�t2H�;H�KH��t�iuH�A��H� �<"= H����= H��H;�u�H����= I���`H�H�6H�vH;�t4H�;H�KH��t�iuH�H� ��!= H����= H��H;��   u�H���q= H�]oA�   EnL�3H��H���   A_A^A]A\_^[]��E� �H�˱B H�M���: ��Ew �H���B H�Mw��: ̐H��L�H D�@UVWATAUAVAWH�h�H��   H�E����H�XM��L��H��3��}H!}�H!}�H!}�@�}g@�}�E3�L�iHM���#  H�F@L�M�D�EwJ��H�H���   H�}� tPH�U�� = H�H�]�H��t�C�� H�MH��t�iuH��   H� �� = �H�U�H�M��z���   �H�U��� = H�H�]�H��t�C��@H�M�H��t�iuH��   H� �l = �H�F@J;�t<H�VHH�M��d
��E3�M��tH�F@J��H�M��3z��I��M;�u�H�U�H�M��z���H��t�kuH��   H��H� � = I��M;������L�}H�N(H��t+H�L�MgD�EwH�U�H���   ��= A�   A�H�M�!H�S H�MA�   H��tDqH�E��L� L�E�M��tEp@��t���H��t�iuH�A��H� �n= A��t!���H�M�H��t�iuH�A��H� �H= H�N0H��t'H�L�MgD�EwH�U�H���   �#= �   H�M�H�aS H�MH��tDqH�E�   �L� L�E�M��tEp��t���H��t�iuH�A��H� ��= ��tH�M�H��t�iuH�A��H� ��= �MǊ�
EgA����   H�^�`   菤: H�EL��D�FXH�U�H�������H��H�EH�H��H  E3�H�U�H���K= H�H��X  H�U�H���4= I�$H�M�H��t�iuH�A��H� �= �H�M�H����   �i��   H��sDv�}g t,H�u�d$( D�t$ E��L�E�H�U�H�M�U��H�EI�$�I�4$L�E�M��tA�huI� A��I��H� ��= �L�E�M��tA�huI� I��A��H� �v= �H�M�����I��H��$�   H�Đ   A_A^A]A\_^]Ð�����H��UWATAUAWH��H��@H�E�����H�XH�pE��H��L��H�yH u H�_ S H�H����  �   p�  H�A@H�H�H�U0H���  ��= H�M0�   H��u<H� S H�H��tpH�M0H���q  �i�g  H���H� ��= �T  L��I�GHH�E�H;���   I�G@H�HH�E��H�UHH���  �^= H�MHH����  I�O�<���H��L�EHH�U0H�M�蜅���D��L��H�U�H���]R �H�M�H��t�iuH���H� �= I�O�����H�U�H��* ����   H�M�H��t�iuH���H� ��= �H�MHH��t�iuH���H� ��= L�L;e��!���H�M0I�( �O  E��H�UHI�O(��9��H�MHH����   I�W�X  H�E3��������   E3�H�U0H�MH��������   I�WH�E3�H�M0��������   H�EHH�H�eH �]H�^�R H�H��tpH�M�H��t�iuH���H� ��= �H�MHH��t$�iuH���H� ��= �@ fff�     H�M0�����H���R H�H��tpH�MH�H�MHH���R H�H��tpH�MH�H�E0H�3�H�M0L�EHM�������A�h��                                                                                                                                                                                                                                                                                                  vcE3�H����A�H1�����A��s=��  v;E3�H����A�H1����=   �u6A��u)A�O	;�u-E3�H�ʰ��A�O0�����
   ��
   ��
   ��
   ;�u,A�ǉD$8H�|$@�"H�=���H�n����!����D$8    �H�|$@�D$t    H�L$p�pϭ��H�D$H����
   L�d$hH�D$HH�|$@�L$0��tH��H���g���A�d$sI���y۳�A�D$�@t3��:��H��$�   H��$�   H�HH��$�   �,����D��$�  H��$�  D��$�  H�\$X�����D$8H�Đ  A_A^A]A\_^[�@UH�� H��H�Mp�έ�H�� ]���������H�T$UH��0H��H���   H�UHH�M@�c����E0H����� H��0]�������������L�L$ D�D$�T$H�L$SVWATAUAVAWH��  HǄ$�   ����M��D��H�����H�\$XH�D$@    A�
   H��$�   ���L��$�  L�\$ E3�L��$�   H��H��$�   �	�����
��H��H�D$h�H��tH���ڳ��N��@t3��8��H�D$H    �
��H��H�xH�|$8H�D$`H�L$`H�� ���H;�P  sH���1���H��H�L$p�ͭ��A�   D�|$TH��$�  H���,  M��tA�$�3ۉ\$4A��A���AD��|$P��t"A;�t��t��tE3�H�y���A�H����D�`L�h����  A;���  ��$�  D��A��   u9��r3L�D$4A��I���Η���\$4A;�uE3�H�����A�N�R�����$�  Hc�A�LE f��-uE��
tE3�H�����A�H�$�����	sE3�H�����A�H1����A�����D�|$T���\$4�f��+uA߉\$4��$�  ���t��u6�CA;�}.Hc�fA�|E 0u"fA�|Ext	fA�|EXu�   �|$P���\$4��%   �D$ L�L$4E��I�Ջ��br��L��H�D$@�D$4;�uE3�H�L���A�H�c���E��tA;�}E3�H�_���A�H�F���L��$�  M��tA�$H�       �L;�u*A��uE�o	A;�u!E3�H�����A�O0����A�
   �A�
   A;�u1Ic�L��L�\$@H�|$8�#H�Ǭ��H�����諘��H�D$@    �H�|$8�D$t    H�L$p��ʭ��H�D$H���A�
   H�t$hH�D$HH�|$8�L$0��tH��H��������fsH���׳��F�@t3��5��H��$�   H��$�   H�HH��$�   �����L��$�  D��$�  H�\$X�]���H�D$@H�Đ  A_A^A]A\_^[����@UH�� H��H�Mp�>ʭ�H�� ]���������H�T$UH��0H��H���   H�UHH�M8�����E0H����� H��0]�������������@SVWH��0H�ɋ�H��u H�L$(�Q-H�L$ H�����E3�E3��oc���H�	��)��;�rE3�L��q��H�����A�P�����H��H����ص�H�΋��1������D�H��0_^[���@SWH��(H��H��H��������yE3�L��?��H�����A�P1������oH���H��(_[�����������@SH��@�=G�   H��uIH�Op���.���H��H��u H�D$(�PRH�����E3�E3�H�D$ �b��̸   ��  ��u�E��L�D$03�H��������yE3�L�p��H�����A�P1����̀|$2 f�D$0  t�oD$0H�T$0H���������|$4 u#�|$< uf�|$2 �D$8|
��xH��@[��؅�~�E3�L�.���H����A�P1������������������@SWH��8�=F�   H��H��uIH�Ko���*���H��H��u H�D$(�PRH�����E3�E3�H�D$ �a��̸   ���  ��u�A��H��H����  ��yE3�L�7>��H�����A�P1�����H��8_[����������������@SVWH��0�=��   I��H��H��uIH��n��膣��H��H��u H�D$(�PRH�����E3�E3�H�D$ ��`��̸   �[�  ��u���A��L��H��H���ܛ����yE3�L�^n��H�w���A�P1�n����f�  H��0_^[�@SVWH��0�=�   A��H��H��uIH�n���梡�H��H��u H�D$(�PRH�����E3�E3�H�D$ �C`��̸   ���  ��u������w9L�Ë�H���������yE3�L��m��H�v���A�P1������f�  H��0_^[�L��m��L�n��H�J����   ��������������������@SVWH��0�=5�   I��H��H��uIH�7m������H��H��u H�D$(�PRH�����E3�E3�H�D$ �s_��̸   ���  ��u�-��L��H��H���������yE3�L��l��H�z���A�P1�����f�  H��0_^[����@SVWH��0�=��   I��H��H��uIH��l���v���H��H��u H�D$(�PRH�����E3�E3�H�D$ ��^��̸   �K�  ��u�
��L��H��H��������yD= �H����u"E3�E3�H�D$(    A�QH�D$     �|^���E3�L�!l��A�P1�8����f�  H��0_^[�����������@SWH��8�=��   H��H��uIH��k��誠��H��H��u H�D$(�PRH�����E3�E3�H�D$ �^��̸   ��  ��u��	��H��H���������x9��t4�X��%��H���=����tH�r���3���[��H��t	3�H��8_[Ë���E3�L�Ok��H�H���A�P1�_������������������@SVWH��0�=��   I��H��H��uIH��j���֟��H��H��u H�D$(�PRH�����E3�E3�H�D$ �3]��̸   ���  ��u����E3�L��H��H���,�����yE3�L��j��H�w���A�P1�����f�  H��0_^[�@SH��@�=W�   ft$0H��(�uIH�Vj���5���H��H��u H�D$(�PRH�����E3�E3�H�D$ �\��̸   �
�  ��u�L��(�H���  ��yE3�L�j��H�{���A�P1�"����f�  fot$0H��@[�@SH��PH�D$8����H��H��uL�� ��E3��Q-H�����������H�D$0    �Q���H��t>H�L$0H�� ���H;�P  s)H�D$(    H�D$     E3�E3�A�Q=H������[����	���H��H�L$@�­��H�C H�H莅��H��tL� H�T$0H��A�PX�D$D    H�L$@�����H�D$0H��P[��������������@UH�� H��H�M@����H�� ]���������H�L$SVWATAUAVAWH��  H�D$x����L�%����L�d$`3�H;�uL�����E3��S-I��������H�q H�t$8�\$4H��$�   �=��L��$�  L�\$ E3�L��$�   I��H��$�   �5���� ���H��H�D$H�@�tH���5ͳ��G�@t3���+��L�������H��L�hL�l$@D��H�D$PH�D$PH ���H;�P  sH���c���H��H�L$h�����H�D$8H�H��Υ��D$4�\$lH�L$h�u�����3�L�d$`H�|$HL�t$XL�l$@D�|$0D:�tI��I���o
����gsH���̳��G�@t3��+��H��$�   H��$�   H�QH��$�   �8��;������9\$4�Ë�H�Đ  A_A^A]A\_^[�����@UH�� H��H�Mh�ο��H�� ]���������H�T$UH��0H��H���   H�UXH�M@����E0H�"���� H��0]�������������L�D$H�T$SVWATAUAVAWH��  H�D$h����H�5����H�t$HH��uL�����E3��Q-H�������L�y L�|$@H��$�   �.��E3�L��$�   H��H��$�   �#��������H��H�D$0�H��tH���2˳��O��@t3��)��E3������H��L�`L�d$(E2�H�D$8H�L$8H�� ���H;�P  sH���^���H��H�L$X豾���I�_hH�����H��$�  H����ڻ�H��H��$�  ����D$\    H�L$X�R�����H�t$HL�|$@H�|$0L�l$PL�d$(D�t$ E��tI��I���I����gsH���]ʳ��G�@t3���(��H��$�   H��$�   H�HH��$�   ����������H�Ā  A_A^A]A\_^[��������@UH�� H��H�MX讽��H�� ]���������H�T$UH�� H��H�UpH�UPH�M(�f���E H�(���� H�� ]����������������@SVWATAUAVAWH��  H�D$h����H�=����H�|$HH��uL�����E3��Q-H��������D$$    L�y L�|$@H��$�   ���E3�L��$�   H��H��$�   ���������H��H�D$0�H��tH���ɳ��K��@t3��'��E3�����H��L�`L�d$(E2�H�D$8H�L$8H�� ���H;�P  sH���?~��H��H�L$X蒼���I�O�j���D$$�D$\    H�L$X�R�����H�|$HL�|$@H�\$0L�l$PL�d$(D�t$ E��tI��I���I����csH���]ȳ��C�@t3���&��H��$�   H��$�   H�HH��$�   �����������D$$H�Ā  A_A^A]A\_^[����@UH�� H��H�MX讻��H�� ]���������H�T$UH�� H��H�UpH�UPH�M(�f���E H�(���� H�� ]����������������@SVWATAUAVAWH��  H�D$h����H�=����H�|$HH��uL�����E3��Q-H��������D$$    L�y L�|$@H��$�   ����E3�L��$�   H��H��$�   ���������H��H�D$0�H��tH���ǳ��K��@t3��%��E3�����H��L�`L�d$(E2�H�D$8H�L$8H�� ���H;�P  sH���?|��H��H�L$X蒺���I�O�D����D$$�D$\    H�L$X�R�����H�|$HL�|$@H�\$0L�l$PL�d$(D�t$ E��tI��I���I����csH���]Ƴ��C�@t3���$��H��$�   H��$�   H�HH��$�   ������������D$$H�Ā  A_A^A]A\_^[����@UH�� H��H�MX讹��H�� ]���������H�T$UH�� H��H�UpH�UPH�M(�f���E H�(���� H�� ]����������������@SVWATAUAVAWH��  HǄ$�   ����H�5����H�t$`H��uL�����E3��Q-H�������L�y L�|$HH�D$8    H��$�   ����L�\$8L�\$ A�   L��$�   H��H��$�   ���������H��H�D$P�H��tH���ų��K��@t3��#��E3�����H��L�`L�d$@E2�H�D$XH�L$XH�� ���H;�P  sH���.z��H��H�L$p聸���H�T$4I�O�n���L�D$8�T$4H���U����D$t    H�L$p�/�����H�t$`L�|$HH�\$PL�l$hL�d$@D�t$0E��tI��I���&����csH���:ĳ��C�@t3���"��H��$�   H��$�   H�HH��$�   ������������H�D$8H�Đ  A_A^A]A\_^[����������������@UH�� H��H�Mp�~���H�� ]���������H�T$UH��0H��H���   H�UhH�M@�3���E0H����� H��0]�������������L�L$ L�D$H�T$SVWATAUAVAWH��  HǄ$�   ����H�=����H�|$`H��uL�s���E3��Q-H���]����L�a L�d$xf���f�D$8f�D$4f�D$0f�D$@A�|$(
��   ���H��t:H�L$HH�� ���H;�P  s%H�D$(    H�D$     E3�E3�A�Q=H���P����f��H��H�L$P�y����H�D$@H�D$ L�L$0L�D$4H�T$8I�L$������D$T    H�L$P�#����Q  H��$�   �!���E3�L��$�   H��H��$�   �~������H��H�D$h�H��tH���%³��K��@t3�� ��E3�����H��L�hL�l$PE2�H�D$pH�L$pH�� ���H;�P  sH���Qw��H��H��$�   衵���H�D$@H�D$ L�L$0L�D$4H�T$8I�L$����Ǆ$�       H��$�   �E�����H�|$`L�d$xH�\$hL�t$HL�l$PD�|$<E��tI��I���<�����csH���P����C�@t3�����H��$�   H��$�   H�HH��$�   ������������D$8H��$�  ��D$4H��$�  ��D$0H��$�  ��L$@H��$   �H�Ġ  A_A^A]A\_^[���������������@UH�� H��H�MP�^���H�� ]���������@UH�� H��H���   �;���H�� ]������H�T$UH��0H��H���   H�UHH�MP��ݼ��E<H������ H��0]�������������@SVWATAUAVAWH��  H�D$p����H�5����H�t$PL�)L�l$HM��uL�$��E3�A�USH���%����H�D$0    H��$�   ����A�   L��$�   H��H��$�   �{���k��H��H�D$8�H��tH��蟿���K��@t3��,��E3��<��H��L�`L�d$(E2�H�D$@H�L$@H�� ���H;�P  sH����t��H��H�L$`�����I���m
��H�D$0�D$d    H�L$`�޲����H�t$PL�l$HH�\$8L�t$XL�d$(D�|$ E��tI��I���������csH���龳��C�@t3��w��H��$�   H��$�   H�HH��$�   �����������H�D$0H�Ā  A_A^A]A\_^[���������������@UH�� H��H�M`�.���H�� ]���������H�T$UH�� H��H�UxH�UXH�M(��ۼ��E H����� H�� ]����������������@SWH��(H�9H��H��uL�7���WSH�����E3��5����H��t?��u:H���H���Μ����t H����Z��H��H��诉��H�ˋ��͠��H��H��H��(_[�E3�L�����H����A�PS�����������H��(H�H��uL������PSH�����E3�����̋@%��� ��H��(����������@SUVWATAUH��(H�3�H;�uL�b����WH�����E3��`����H���a��H��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              